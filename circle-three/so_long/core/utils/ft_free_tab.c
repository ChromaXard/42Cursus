/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:05:52 by event             #+#    #+#             */
/*   Updated: 2023/03/11 13:08:42 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

void	ft_free_tab(char **tab)
{
	int	line;

	line = 0;
	while (tab[line])
	{
		if (tab[line])
			free(tab[line]);
		line++;
	}
	free(tab);
}
