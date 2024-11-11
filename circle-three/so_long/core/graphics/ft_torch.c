/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_torch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:54:32 by akastler          #+#    #+#             */
/*   Updated: 2023/04/04 16:55:53 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_destroy_torch2(t_vars_game *info, mlx_image_t *player,
t_images *img)
{
	int	inst;

	inst = 0;
	if (info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] == 'T')
	{
		info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] = '0';
		inst = ft_find_instance_ennemy(player->instances[0].y + 64,
				player->instances[0].x, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = false;
		img->torch2_ok->instances[inst].enabled = false;
	}
	else if (info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] == 'T')
	{
		info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] = '0';
		inst = ft_find_instance_ennemy(player->instances[0].y - 64,
				player->instances[0].x, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = false;
		img->torch2_ok->instances[inst].enabled = false;
	}
}

void	ft_destroy_torch(t_vars_game *info, mlx_image_t *player, t_images *img)
{
	int	inst;

	inst = 0;
	if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) + 1] == 'T')
	{
		info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) + 1] = '0';
		inst = ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x + 64, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = false;
		img->torch2_ok->instances[inst].enabled = false;
	}
	else if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] == 'T')
	{
		info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] = '0';
		inst = ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x - 64, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = false;
		img->torch2_ok->instances[inst].enabled = false;
	}
	else
		ft_destroy_torch2(info, player, img);
}

static void	ft_place_torch2(t_vars_game *info, mlx_image_t *player,
t_images *img)
{
	int	inst;

	inst = 0;
	if (info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] == '0')
	{
		info->map[(player->instances[0].y / 64) + 1]
		[(player->instances[0].x / 64)] = 'T';
		inst = ft_find_instance_ennemy(player->instances[0].y + 64,
				player->instances[0].x, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = true;
		img->torch2_ok->instances[inst].enabled = true;
	}
	else if (info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] == '0')
	{
		info->map[(player->instances[0].y / 64) - 1]
		[(player->instances[0].x / 64)] = 'T';
		inst = ft_find_instance_ennemy(player->instances[0].y - 64,
				player->instances[0].x, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = true;
		img->torch2_ok->instances[inst].enabled = true;
	}
}

void	ft_place_torch(t_vars_game *info, mlx_image_t *player, t_images *img)
{
	int	inst;

	inst = 0;
	if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) + 1] == '0')
	{
		info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) + 1] = 'T';
		inst = ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x + 64, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = true;
		img->torch2_ok->instances[inst].enabled = true;
	}
	else if (info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] == '0')
	{
		info->map[(player->instances[0].y / 64)]
		[(player->instances[0].x / 64) - 1] = 'T';
		inst = ft_find_instance_ennemy(player->instances[0].y,
				player->instances[0].x - 64, img->torch1_ok);
		img->torch1_ok->instances[inst].enabled = true;
		img->torch2_ok->instances[inst].enabled = true;
	}
	else
		ft_place_torch2(info, player, img);
}
