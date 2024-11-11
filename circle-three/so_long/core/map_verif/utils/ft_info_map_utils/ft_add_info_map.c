/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_info_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:35:23 by event             #+#    #+#             */
/*   Updated: 2023/03/11 14:58:57 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes.h"

void	ft_add_info_map(char *line, t_vars_game *info, int nb_line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			info->nb_wall++;
		else if (line[i] == 'P')
		{
			info->nb_start_pos++;
			info->cur.y = nb_line;
			info->cur.x = i;
		}
		else if (line[i] == 'C')
			info->nb_colec++;
		else if (line[i] == 'E')
			info->nb_exit++;
		i++;
	}
}
