/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:40:26 by chromaxard        #+#    #+#             */
/*   Updated: 2023/04/04 10:48:25 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_place(t_vars_game *info, t_images *img,
int wall1, t_position cur)
{
	int	wall2;

	wall2 = 0;
	if (info->nb_blocks == 0)
	{
		ft_printf("Pas de blocks en stock !\n");
		return ;
	}
	wall2 = ft_find_instance_ennemy(img->wall_ok->instances[wall1].y,
			img->wall_ok->instances[wall1].x, img->cracked_wall_ok);
	img->cracked_wall_ok->instances[wall2].enabled = true;
	img->wall_ok->instances[wall1].enabled = true;
	info->status_wall[wall1] = 3;
	info->map[cur.y / 64][cur.x / 64] = '9';
	info->nb_blocks--;
}

static void	ft_place_wall2(t_vars_game *info, mlx_image_t *player,
t_images *img, mlx_t *id)
{
	int	instance;

	instance = 0;
	(void)id;
	if (info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] == '0')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y + 64,
				player->instances[0].x, img->wall_ok);
		ft_place(info, img, instance,
			(t_position){player->instances[0].y + 64, player->instances[0].x});
	}
	else if (info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] == '0')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y - 64,
				player->instances[0].x, img->wall_ok);
		ft_place(info, img, instance,
			(t_position){player->instances[0].y - 64, player->instances[0].x});
	}
}

void	ft_place_wall(t_vars_game *info, mlx_image_t *player,
t_images *img, mlx_t *id)
{
	int	instance;

	instance = 0;
	if (info->map[(player->instances[0].y / 64)][(player->instances[0].x / 64)
		+ 1] == '0')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x + 64, img->wall_ok);
		ft_place(info, img, instance,
			(t_position){player->instances[0].y, player->instances[0].x + 64});
	}
	else if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] == '0')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x - 64, img->wall_ok);
		ft_place(info, img, instance,
			(t_position){player->instances[0].y, player->instances[0].x - 64});
	}
	else
		ft_place_wall2(info, player, img, id);
}
