/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:01 by akastler          #+#    #+#             */
/*   Updated: 2023/02/14 09:43:42 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_push_swap(t_list *lst, char **argv)
{
	lst = malloc(sizeof(t_list));
	ft_init(lst);
	if (ft_build_list(argv, lst) == -1)
	{
		ft_clear_list(lst);
		free(lst);
		return (-1);
	}
	if (ft_verif_dup(lst) == -1)
	{
		ft_clear_list(lst);
		free(lst);
		return (-1);
	}
	ft_algo(lst);
	ft_clear_list(lst);
	free(lst);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	if (argc > 1)
		if (ft_push_swap(list, argv) == -1)
			write(2, "Error\n", 6);
	return (0);
}
