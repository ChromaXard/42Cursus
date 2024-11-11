/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:38:34 by event             #+#    #+#             */
/*   Updated: 2023/04/03 09:08:56 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

static void	fill(char **tab, t_position size, t_position cur, char to_fill)
{
	if (tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == 'P'
		|| tab[cur.y][cur.x] == 'E' || tab[cur.y][cur.x] == 'C'
		|| tab[cur.y][cur.x] == 'K')
	{
		tab[cur.y][cur.x] = 'F';
		fill(tab, size, (t_position){cur.y, cur.x + 1}, to_fill);
		fill(tab, size, (t_position){cur.y, cur.x - 1}, to_fill);
		fill(tab, size, (t_position){cur.y + 1, cur.x}, to_fill);
		fill(tab, size, (t_position){cur.y - 1, cur.x}, to_fill);
	}
}

static int	ft_check_fill(char **tab)
{
	int	line;
	int	i;
	int	err;

	line = -1;
	i = 0;
	err = 1;
	while (tab[++line])
	{
		i = 0;
		while (tab[line][i])
		{
			if (tab[line][i] != '1' && tab[line][i] != '0'
				&& tab[line][i] != 'F')
			{
				err = -1;
				break ;
			}
			i++;
		}
		if (err == -1)
			break ;
	}
	return (err);
}

int	flood_fill(char **tab, t_position size, t_position begin)
{
	char	**cpy_tab;

	cpy_tab = ft_dup_tab(tab);
	fill(cpy_tab, size, begin, '0');
	if (ft_check_fill(cpy_tab) == 1)
	{
		ft_free_tab(cpy_tab);
		return (1);
	}
	else
	{
		ft_free_tab(cpy_tab);
		return (-1);
	}
	return (1);
}
