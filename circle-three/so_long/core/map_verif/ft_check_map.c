/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:27:02 by event             #+#    #+#             */
/*   Updated: 2023/04/05 14:43:59 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static char	**errors(char **str, t_vars_game *vars, int fd)
{
	write(2, "Error\n", 6);
	if (vars->status == -1)
		ft_printf("cette carte est invalide.\n");
	else
		ft_printf("La map ne peut pas être finie.");
	ft_free_tab(str);
	close(fd);
	return (NULL);
}

static void	ft_modify_walls(char **map)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (map[i] && i < ft_nb_line(map) - 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (j > 0 && j < (int)ft_strlen(map[i]) - 1)
				if (map[i][j] == '1')
					map[i][j] = '9';
			j++;
		}
		ft_printf("%s\n", map[i]);
		i++;
	}
}

char	**check_map(char *map, t_vars_game *vars)
{
	char	**str;
	char	*line_map;
	int		fd;

	fd = ft_check_file(map);
	if (fd < 0)
	{
		write(2, "Error\nWhere is my .ber map ?\n", 30);
		return (NULL);
	}
	str = NULL;
	line_map = ft_get_line_map(fd);
	close(fd);
	str = ft_split(line_map, '\n');
	free(line_map);
	ft_replace_nl(str);
	ft_info_map(str, vars);
	if (vars->status == -1 || flood_fill(str, vars->len, vars->cur) == -1)
	{
		return (errors(str, vars, fd));
	}
	ft_modify_walls(str);
	return (str);
}
