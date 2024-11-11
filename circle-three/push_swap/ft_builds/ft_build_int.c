/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:02:10 by akastler          #+#    #+#             */
/*   Updated: 2023/01/27 08:51:20 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_build_int(char *str, t_list *lst)
{
	if (ft_verif_int(str) == -1)
		return (-1);
	else
	{
		if (lst->last)
			ft_pushbottom(lst, ft_atoi(str), lst->last->index + 1);
		else
			ft_pushbottom(lst, ft_atoi(str), 0);
	}
	return (0);
}
