/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chromaxard <chromaxard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:26:03 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 00:19:33 by chromaxard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_img_window3(char **map, t_images *img, mlx_t *id,
		t_position player)
{
	t_position	cur;
	int			i;

	cur.y = -1;
	i = 0;
	ft_put_image(player, map, img, id);
	map[player.y][player.x] = '0';
	while (map[++cur.y])
	{
		cur.x = -1;
		while (map[cur.y][++cur.x])
		{
			mlx_image_to_window(id, img->torch1_ok, cur.x * 64,
				cur.y * 64);
			mlx_image_to_window(id, img->torch2_ok, cur.x * 64,
				cur.y * 64);
			img->torch1_ok->instances[i].enabled = false;
			img->torch2_ok->instances[i].enabled = false;
			mlx_image_to_window(id, img->light_ok, cur.x * 64, cur.y * 64);
			img->light_ok->instances[i].enabled = false;
			i++;
		}
	}
}

static void	ft_img_window2(char **map, t_images *img, mlx_t *id,
		t_position player)
{
	t_position	cur;

	cur.y = -1;
	while (map[++cur.y])
	{
		cur.x = -1;
		while (map[cur.y][++cur.x])
		{
			if (map[cur.y][cur.x] != '1')
			{
				mlx_image_to_window(id, img->cracked_wall_ok, cur.x * 64, cur.y
					* 64);
				mlx_image_to_window(id, img->wall_ok, cur.x * 64, cur.y * 64);
				if (map[cur.y][cur.x] != '9')
				{
					img->cracked_wall_ok->instances
					[img->cracked_wall_ok->count - 1].enabled = false;
					img->wall_ok->instances[img->wall_ok->count - 1].enabled
						= false;
				}
			}
		}
	}
	ft_img_window3(map, img, id, player);
}

void	ft_img_window(char **map, t_images *img, mlx_t *id)
{
	t_position	cur;
	t_position	player;

	cur.x = -1;
	cur.y = -1;
	while (map[++cur.y])
	{
		cur.x = -1;
		while (map[cur.y][++cur.x])
			mlx_image_to_window(id, img->ground_ok, cur.x * 64, cur.y * 64);
	}
	cur.x = -1;
	cur.y = -1;
	while (map[++cur.y])
	{
		cur.x = -1;
		while (map[cur.y][++cur.x])
		{
			if (map[cur.y][cur.x] != 'P' && map[cur.y][cur.x] != '9')
				ft_put_image(cur, map, img, id);
			else if (map[cur.y][cur.x] != '9')
				player = (t_position){cur.y, cur.x};
		}
	}
	ft_img_window2(map, img, id, player);
}
