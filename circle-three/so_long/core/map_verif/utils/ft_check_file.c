/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:29:13 by event             #+#    #+#             */
/*   Updated: 2023/03/11 14:58:34 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

int	ft_check_file(char *map)
{
	int	len_name;
	int	fd;

	len_name = ft_strlen(map);
	fd = 0;
	if (!(map[len_name - 1] == 'r' && map[len_name - 2] == 'e'
			&& map[len_name - 3] == 'b' && map[len_name - 4] == '.'))
		return (-1);
	fd = open(map, O_RDONLY);
	return (fd);
}
