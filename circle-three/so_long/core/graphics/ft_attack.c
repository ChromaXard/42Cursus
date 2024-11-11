/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:44:03 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 11:52:48 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_status_attack(t_vars_game *info, t_images *img, int instance,
t_position cur)
{
	if (info->status_ennemy[instance] == 3)
	{
		img->ennemy_ok->instances[instance].enabled = false;
		info->status_ennemy[instance]--;
	}
	else if (info->status_ennemy[instance] == 2)
	{
		img->ennemy1_ok->instances[instance].enabled = false;
		info->status_ennemy[instance]--;
	}
	else if (info->status_ennemy[instance] == 1)
	{
		img->ennemy2_ok->instances[instance].enabled = false;
		info->status_ennemy[instance]--;
		info->map[cur.y / 64][cur.x / 64] = 'X';
	}
}

static void	ft_attack2(t_vars_game *info, mlx_image_t *player, t_images *img,
		mlx_t *id)
{
	int	instance;

	instance = 0;
	(void)id;
	if (info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] == 'K')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y + 64,
				player->instances[0].x, img->ennemy_ok);
		ft_status_attack(info, img, instance,
			(t_position){player->instances[0].y + 64, player->instances[0].x});
	}
	if (info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] == 'K')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y - 64,
				player->instances[0].x, img->ennemy_ok);
		ft_status_attack(info, img, instance,
			(t_position){player->instances[0].y - 64, player->instances[0].x});
	}
}

void	ft_attack(t_vars_game *info, mlx_image_t *player,
t_images *img, mlx_t *id)
{
	int	instance;

	instance = 0;
	if (info->map[(player->instances[0].y / 64)][(player->instances[0].x / 64)
		+ 1] == 'K')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x + 64, img->ennemy_ok);
		ft_status_attack(info, img, instance,
			(t_position){player->instances[0].y, player->instances[0].x + 64});
	}
	if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] == 'K')
	{
		instance
			= ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x - 64, img->ennemy_ok);
		ft_status_attack(info, img, instance,
			(t_position){player->instances[0].y, player->instances[0].x - 64});
	}
	ft_attack2(info, player, img, id);
}
