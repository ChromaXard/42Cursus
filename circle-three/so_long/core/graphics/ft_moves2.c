/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 08:31:33 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 15:08:37 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_move_x(t_images *img, int identify)
{
	if (identify == 1)
	{
		img->player_up_ok->instances[0].x += 64;
		img->player_up_right_ok->instances[0].x += 64;
		img->player_iron_up_ok->instances[0].x += 64;
		img->player_iron_up_right_ok->instances[0].x += 64;
		img->player_gold_up_ok->instances[0].x += 64;
		img->player_gold_up_right_ok->instances[0].x += 64;
		img->player_diamond_up_ok->instances[0].x += 64;
		img->player_diamond_up_right_ok->instances[0].x += 64;
	}
	else if (identify == -1)
	{
		img->player_up_ok->instances[0].x -= 64;
		img->player_up_right_ok->instances[0].x -= 64;
		img->player_iron_up_ok->instances[0].x -= 64;
		img->player_iron_up_right_ok->instances[0].x -= 64;
		img->player_gold_up_ok->instances[0].x -= 64;
		img->player_gold_up_right_ok->instances[0].x -= 64;
		img->player_diamond_up_ok->instances[0].x -= 64;
		img->player_diamond_up_right_ok->instances[0].x -= 64;
	}
}

void	ft_move_y(t_images *img, int identify)
{
	if (identify == 1)
	{
		img->player_up_ok->instances[0].y += 64;
		img->player_up_right_ok->instances[0].y += 64;
		img->player_iron_up_ok->instances[0].y += 64;
		img->player_iron_up_right_ok->instances[0].y += 64;
		img->player_gold_up_ok->instances[0].y += 64;
		img->player_gold_up_right_ok->instances[0].y += 64;
		img->player_diamond_up_ok->instances[0].y += 64;
		img->player_diamond_up_right_ok->instances[0].y += 64;
	}
	else if (identify == -1)
	{
		img->player_up_ok->instances[0].y -= 64;
		img->player_up_right_ok->instances[0].y -= 64;
		img->player_iron_up_ok->instances[0].y -= 64;
		img->player_iron_up_right_ok->instances[0].y -= 64;
		img->player_gold_up_ok->instances[0].y -= 64;
		img->player_gold_up_right_ok->instances[0].y -= 64;
		img->player_diamond_up_ok->instances[0].y -= 64;
		img->player_diamond_up_right_ok->instances[0].y -= 64;
	}
}

void	ft_ennemy(t_images *img, char **map, mlx_t *id, t_vars_game *info)
{
	ft_printf("You have been eaten by a zombie.\n");
	ft_escape(img, map, id, info);
}
