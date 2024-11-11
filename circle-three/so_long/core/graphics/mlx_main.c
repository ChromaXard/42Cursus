/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:11:48 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 14:43:04 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_delete_imgs(t_images *img)
{
	mlx_delete_texture(img->player_up);
	mlx_delete_texture(img->player_up_right);
	mlx_delete_texture(img->player_iron_up);
	mlx_delete_texture(img->player_iron_up_right);
	mlx_delete_texture(img->player_gold_up);
	mlx_delete_texture(img->player_gold_up_right);
	mlx_delete_texture(img->player_diamond_up);
	mlx_delete_texture(img->player_diamond_up_right);
	mlx_delete_texture(img->wall);
	mlx_delete_texture(img->cracked_wall);
	mlx_delete_texture(img->corner);
	mlx_delete_texture(img->collec);
	mlx_delete_texture(img->ground);
	mlx_delete_texture(img->exit_close1);
	mlx_delete_texture(img->exit_close2);
	mlx_delete_texture(img->exit_open);
	mlx_delete_texture(img->ennemy);
	mlx_delete_texture(img->ennemy1);
	mlx_delete_texture(img->ennemy2);
	mlx_delete_texture(img->exp);
	mlx_delete_texture(img->dark_exp);
	mlx_delete_texture(img->torch1);
	mlx_delete_texture(img->torch2);
	mlx_delete_texture(img->light);
}

static void	ft_hook2(t_all *all, mlx_image_t *player_up)
{
	if (mlx_is_key_down(all->id, MLX_KEY_T))
		ft_place_torch(all->info, player_up, all->img);
	else if (mlx_is_key_down(all->id, MLX_KEY_G))
		ft_destroy_torch(all->info, player_up, all->img);
}

void	ft_hook(mlx_key_data_t keydata, void *mlx)
{
	t_all		*all;
	mlx_image_t	*player_up;

	all = mlx;
	player_up = all->img->player_up_ok;
	(void)keydata;
	if (mlx_is_key_down(all->id, MLX_KEY_ESCAPE))
		ft_escape(all->img, all->map, all->id, all->info);
	else if (mlx_is_key_down(all->id, MLX_KEY_W))
		ft_up(player_up, all->map, all->info, all->img);
	else if (mlx_is_key_down(all->id, MLX_KEY_A))
		ft_left(player_up, all->map, all->info, all->img);
	else if (mlx_is_key_down(all->id, MLX_KEY_S))
		ft_down(player_up, all->map, all->info, all->img);
	else if (mlx_is_key_down(all->id, MLX_KEY_D))
		ft_right(player_up, all->map, all->info, all->img);
	else if (mlx_is_key_down(all->id, MLX_KEY_E))
		ft_attack(all->info, player_up, all->img, all->id);
	else if (mlx_is_key_down(all->id, MLX_KEY_F))
		ft_break_wall(all->info, player_up, all->img, all->id);
	else if (mlx_is_key_down(all->id, MLX_KEY_R))
		ft_place_wall(all->info, player_up, all->img, all->id);
	else
		ft_hook2(all, player_up);
}

static void	ft_init_tab_ennemy(int *tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
		tab[i++] = 3;
}

void	mlx_funct(char **map, t_vars_game *info)
{
	t_images	*imgs;
	t_all		all;

	info->id = mlx_init(info->len.x * 64, info->len.y * 64, "test", true);
	if (!info->id)
		ft_printf("ça a planté !");
	else
	{
		imgs = malloc(sizeof(t_images));
		ft_create_texture(imgs, info->id);
		ft_img_window(map, imgs, info->id);
		info->status_ennemy = malloc(sizeof(int) * imgs->ennemy_ok->count);
		ft_init_tab_ennemy(info->status_ennemy, imgs->ennemy_ok->count);
		info->status_wall = malloc(sizeof(int) * imgs->wall_ok->count);
		ft_init_tab_ennemy(info->status_wall, imgs->wall_ok->count);
		info->map = map;
		all.id = info->id;
		all.img = imgs;
		all.map = map;
		all.info = info;
		mlx_key_hook(info->id, ft_hook, &all);
		mlx_loop_hook(info->id, ft_anim, &all);
		mlx_loop(info->id);
		mlx_terminate(info->id);
	}
}
