/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_veri_dup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:50:21 by akastler          #+#    #+#             */
/*   Updated: 2023/01/27 11:52:13 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_verif_dup(t_list *lst)
{
	t_elem	*iterator1;
	t_elem	*iterator2;

	iterator1 = lst->first;
	iterator2 = lst->first;
	while (iterator2)
	{
		while (iterator1)
		{
			if (iterator1->value == iterator2->value)
				if (!(iterator1->index == iterator2->index))
					return (-1);
			iterator1 = iterator1->next;
		}
		iterator2 = iterator2->next;
		iterator1 = lst->first;
	}
	return (0);
}
