/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:01:01 by event             #+#    #+#             */
/*   Updated: 2023/04/05 13:50:42 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv)
{
	t_vars_game	*vars;
	char		**map;

	vars = malloc(sizeof(t_vars_game));
	if (argc == 2)
	{
		ft_init_vars(vars);
		map = check_map(argv[1], vars);
		if (map)
		{
			ft_printf("Let the game begin !\nCommands :\nWASD or ZQSD : move\n");
			ft_printf("E : hit the ennemy\nF/R : destroy/place block\n");
			ft_printf("G/T : destroy/place torch\n");
			ft_printf("Objective : pick up the %d diamonds ont the map\n",
				vars->nb_colec);
			mlx_funct(map, vars);
			ft_free_tab(map);
		}
	}
	else
		write(2, "Error\nI only want a correct .ber map.\n", 39);
	free(vars);
}
