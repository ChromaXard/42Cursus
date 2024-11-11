/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_instance.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chromaxard <chromaxard@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:10:51 by chromaxard        #+#    #+#             */
/*   Updated: 2023/03/30 15:31:00 by chromaxard       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

int	ft_find_instance(mlx_image_t *player, mlx_image_t *img, int nb_img)
{
	int	instance;

	instance = 0;
	(void)nb_img;
	while (instance < img->count)
	{
		if (img->instances[instance].y == player->instances[0].y
			&& img->instances[instance].x == player->instances[0].x)
			return (instance);
		instance++;
	}
	return (-1);
}
