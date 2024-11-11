/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:36:10 by event             #+#    #+#             */
/*   Updated: 2023/03/11 13:36:55 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes.h"

int	ft_check_wall(char **str, int nb_line)
{
	int	line;
	int	i;

	i = 0;
	line = -1;
	while (str[++line])
	{
		i = 0;
		if (line == 0 || line == nb_line - 1)
		{
			while (str[line][i])
			{
				if (str[line][i] != '1')
					return (-1);
				i++;
			}
		}
		else
		{
			if (str[line][0] != '1' || str[line][ft_strlen(str[line])
				- 1] != '1')
				return (-1);
		}
	}
	return (0);
}
