/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:32:00 by akastler          #+#    #+#             */
/*   Updated: 2023/02/10 14:52:17 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_build_list(char **argv, t_list *lst)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_verif_char(argv[i]) == 0)
		{
			if (ft_verif_multiple_int(argv[i]) == 1)
			{
				if (ft_build_str(argv[i], lst) == -1)
					return (-1);
			}
			else
			{
				if (ft_build_int(argv[i], lst) == -1)
					return (-1);
			}
		}
		else
			return (-1);
		i++;
	}
	return (0);
}
