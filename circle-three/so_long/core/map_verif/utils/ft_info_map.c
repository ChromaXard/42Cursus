/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:33:36 by event             #+#    #+#             */
/*   Updated: 2023/04/03 09:07:10 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

void	ft_info_map(char **map, t_vars_game *info)
{
	int	line;

	line = 0;
	info->len.x = ft_strlen(map[0]);
	while (map[line])
	{
		if (ft_strlen(map[line]) != (size_t)info->len.x)
		{
			info->status = -1;
			break ;
		}
		ft_add_info_map(map[line], info, line);
		line++;
	}
	map[line] = NULL;
	info->len.y = line;
	if (info->nb_exit != 1 || info->nb_start_pos != 1 || info->nb_colec < 1
		|| ft_check_wall(map, line) == -1)
		info->status = -1;
}
