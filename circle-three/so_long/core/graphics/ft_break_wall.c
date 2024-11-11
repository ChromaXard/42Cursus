/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_break_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 18:14:58 by akastler          #+#    #+#             */
/*   Updated: 2023/04/04 10:34:13 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static int	ft_find_crack_wall(t_images *img, int instance)
{
	int	inst;

	inst = 0;
	while ((img->wall_ok->instances[instance].x
			!= img->cracked_wall_ok->instances[inst].x)
		|| (img->wall_ok->instances[instance].y
			!= img->cracked_wall_ok->instances[inst].y))
		inst++;
	return (inst);
}

static void	ft_status_break(t_vars_game *info, t_images *img, int instance,
t_position cur)
{
	int	inst_wall;

	inst_wall = 0;
	(void)cur;
	if (info->status_wall[instance] == 3)
	{
		img->wall_ok->instances[instance].enabled = false;
		info->status_wall[instance]--;
		info->map[cur.y / 64][cur.x / 64] = '9';
	}
	else if (info->status_wall[instance] == 2)
	{
		inst_wall = ft_find_crack_wall(img, instance);
		img->cracked_wall_ok->instances[inst_wall].enabled = false;
		info->status_wall[instance]--;
		info->map[cur.y / 64][cur.x / 64] = '0';
		info->nb_blocks++;
	}
}

static void	ft_break_wall2(t_vars_game *info, mlx_image_t *player,
t_images *img, mlx_t *id)
{
	int	instance;

	instance = 0;
	(void)id;
	if (info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] == '9')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y + 64,
				player->instances[0].x, img->wall_ok);
		ft_status_break(info, img, instance,
			(t_position){player->instances[0].y + 64, player->instances[0].x});
	}
	else if (info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] == '9')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y - 64,
				player->instances[0].x, img->wall_ok);
		ft_status_break(info, img, instance,
			(t_position){player->instances[0].y - 64, player->instances[0].x});
	}
}

void	ft_break_wall(t_vars_game *info, mlx_image_t *player,
t_images *img, mlx_t *id)
{
	int	instance;

	instance = 0;
	if (info->map[(player->instances[0].y / 64)][(player->instances[0].x / 64)
		+ 1] == '9')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x + 64, img->wall_ok);
		ft_status_break(info, img, instance,
			(t_position){player->instances[0].y, player->instances[0].x + 64});
	}
	else if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] == '9')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x - 64, img->wall_ok);
		ft_status_break(info, img, instance,
			(t_position){player->instances[0].y, player->instances[0].x - 64});
	}
	else
		ft_break_wall2(info, player, img, id);
}
