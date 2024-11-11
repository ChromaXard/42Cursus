/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sorted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:06:23 by akastler          #+#    #+#             */
/*   Updated: 2023/01/28 17:16:51 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_list_sorted(t_list *lst)
{
	t_elem	*iter;
	t_elem	*iter2;

	iter = lst->first;
	iter2 = lst->first->next;
	while (iter2)
	{
		if (iter->value > iter2->value)
			return (-1);
		iter = iter->next;
		iter2 = iter2->next;
	}
	return (1);
}
