/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:23:17 by event             #+#    #+#             */
/*   Updated: 2023/03/20 16:17:59 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.h"

int	main(int argc, char **argv, char **env)
{
	int	f1;
	int	f2;

	if (argc == 5)
	{
		f1 = open(argv[1], O_RDONLY);
		if (f1 < 0)
		{
			perror(NULL);
		}
		else
		{
			f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
			if (f2 < 0)
				exit(1);
			pipex(f1, f2, argv, env);
			exit(1);
		}
	}
	else
		write(2, "Error\nIl faut 4 arguments.\n", 28);
	exit(1);
}
