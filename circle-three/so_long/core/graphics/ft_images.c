/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:30:57 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 11:53:58 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_put_player(mlx_t *id, t_images *img, t_position cur)
{
	mlx_image_to_window(id, img->player_up_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_up_right_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_iron_up_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_iron_up_right_ok,
		cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_gold_up_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_gold_up_right_ok,
		cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_diamond_up_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->player_diamond_up_right_ok,
		cur.x * 64, cur.y * 64);
	img->player_up_right_ok->instances[0].enabled = false;
	img->player_iron_up_ok->instances[0].enabled = false;
	img->player_iron_up_right_ok->instances[0].enabled = false;
	img->player_gold_up_ok->instances[0].enabled = false;
	img->player_gold_up_right_ok->instances[0].enabled = false;
	img->player_diamond_up_ok->instances[0].enabled = false;
	img->player_diamond_up_right_ok->instances[0].enabled = false;
}

static void	ft_put_exit(mlx_t *id, t_images *img, t_position cur)
{
	mlx_image_to_window(id, img->exit_close1_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->exit_close2_ok, cur.x * 64, cur.y * 64);
	mlx_image_to_window(id, img->exit_open_ok, cur.x * 64, cur.y * 64);
	img->exit_open_ok->instances[0].enabled = false;
}

static void	ft_put_wall(t_position cur, char **map, t_images *img, mlx_t *id)
{
	if ((cur.y == 0 && cur.x == 0) || (cur.y == 0
			&& cur.x == (int)ft_strlen(map[cur.y]) - 1)
		|| (cur.y == ft_nb_line(map) - 1 && cur.x == 0)
		|| (cur.y == ft_nb_line(map) - 1
			&& cur.x == (int)ft_strlen(map[cur.y]) - 1))
		mlx_image_to_window(id, img->corner_ok, cur.x * 64, cur.y * 64);
	else
		mlx_image_to_window(id, img->wall_ok, cur.x * 64, cur.y * 64);
}

void	ft_put_image(t_position cur, char **map, t_images *img, mlx_t *id)
{
	if (map[cur.y][cur.x] == '1')
	{
		ft_put_wall(cur, map, img, id);
	}
	else if (map[cur.y][cur.x] == '9')
	{
		mlx_image_to_window(id, img->cracked_wall_ok, cur.x * 64, cur.y * 64);
		mlx_image_to_window(id, img->wall_ok, cur.x * 64, cur.y * 64);
	}
	else if (map[cur.y][cur.x] == 'P')
		ft_put_player(id, img, cur);
	else if (map[cur.y][cur.x] == 'C')
		mlx_image_to_window(id, img->collec_ok, cur.x * 64, cur.y * 64);
	else if (map[cur.y][cur.x] == 'E')
		ft_put_exit(id, img, cur);
	else if (map[cur.y][cur.x] == 'K')
	{
		mlx_image_to_window(id, img->exp_ok, cur.x * 64, cur.y * 64);
		mlx_image_to_window(id, img->dark_exp_ok, cur.x * 64, cur.y * 64);
		mlx_image_to_window(id, img->ennemy2_ok, cur.x * 64, cur.y * 64);
		mlx_image_to_window(id, img->ennemy1_ok, cur.x * 64, cur.y * 64);
		mlx_image_to_window(id, img->ennemy_ok, cur.x * 64, cur.y * 64);
	}
}
