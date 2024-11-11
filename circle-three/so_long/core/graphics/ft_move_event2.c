/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_event2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:00:21 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 15:00:48 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static int	ft_find_instance2(mlx_image_t *player, mlx_image_t *img)
{
	int	instance;

	instance = 0;
	while (instance < img->count)
	{
		if (img->instances[instance].y == player->instances[0].y
			&& img->instances[instance].x == player->instances[0].x)
			return (instance);
		instance++;
	}
	return (-1);
}

void	ft_pos_is_x(char **map, t_vars_game *info, mlx_image_t *player,
		t_images *img)
{
	(void)map;
	map[(player->instances[0].y) / 64][(player->instances[0].x) / 64] = '0';
	img->exp_ok->instances[ft_find_instance2(player, img->exp_ok)]
		.enabled = false;
	img->dark_exp_ok->instances[ft_find_instance2(player, img->exp_ok)]
		.enabled = false;
	info->nb_exp++;
	ft_printf("You've gained experience !\n");
	ft_printf("You now have %d experience points\n", info->nb_exp);
}
