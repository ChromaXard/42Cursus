/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_nl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:31:37 by event             #+#    #+#             */
/*   Updated: 2023/03/11 13:32:16 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

void	ft_replace_nl(char **str)
{
	int	line;
	int	i;

	line = 0;
	i = 0;
	while (str[line])
	{
		i = 0;
		while (str[line][i])
		{
			if (str[line][i] == '\n')
				str[line][i] = '\0';
			i++;
		}
		line++;
	}
}
