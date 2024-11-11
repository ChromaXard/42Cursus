/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:31:28 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 15:07:18 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_escape(t_images *img, char **map, mlx_t *id, t_vars_game *info)
{
	mlx_close_window(id);
	free(info->status_wall);
	free(info->status_ennemy);
	free(info);
	ft_delete_imgs(img);
	ft_free_tab(map);
	free(img);
	ft_printf("The mission failed...\n");
	mlx_terminate(id);
	exit(0);
}
