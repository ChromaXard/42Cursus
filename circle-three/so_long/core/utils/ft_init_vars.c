/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:10:00 by event             #+#    #+#             */
/*   Updated: 2023/04/04 09:34:47 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_init_vars(t_vars_game *info)
{
	info->cur.y = 0;
	info->cur.x = 0;
	info->len.y = 0;
	info->len.x = 0;
	info->nb_wall = 0;
	info->nb_colec = 0;
	info->nb_start_pos = 0;
	info->nb_exit = 0;
	info->status = 0;
	info->col_pick = 0;
	info->nb_move = 0;
	info->indicator = 0;
	info->l_or_r = 0;
	info->nb_exp = 0;
	info->id = NULL;
	info->mlx_string = NULL;
	info->status_ennemy = NULL;
	info->status_wall = NULL;
	info->map = NULL;
	info->nb_blocks = 0;
}
