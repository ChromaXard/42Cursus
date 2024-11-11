/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:55:24 by akastler          #+#    #+#             */
/*   Updated: 2023/03/22 09:55:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

char	**ft_dup_tab(char **tab)
{
	char	**cpy_tab;
	int		nb_line;
	int		i;

	nb_line = 0;
	i = 0;
	cpy_tab = NULL;
	while (tab[nb_line])
		nb_line++;
	cpy_tab = ft_calloc(sizeof(char *), nb_line + 1);
	nb_line = 0;
	while (tab[nb_line])
	{
		i = 0;
		cpy_tab[nb_line] = ft_calloc(sizeof(char), ft_strlen(tab[nb_line]) + 1);
		while (tab[nb_line][i])
		{
			cpy_tab[nb_line][i] = tab[nb_line][i];
			i++;
		}
		nb_line++;
	}
	return (cpy_tab);
}
