/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 09:41:54 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 15:06:39 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_end_game(t_vars_game *info, mlx_t *id, char **map, t_images *img)
{
	mlx_close_window(id);
	free(info->status_wall);
	free(info->status_ennemy);
	free(info);
	ft_delete_imgs(img);
	ft_free_tab(map);
	free(img);
	ft_printf("You win !\n");
	mlx_terminate(id);
	exit(0);
}
