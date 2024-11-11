/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:40:33 by akastler          #+#    #+#             */
/*   Updated: 2023/01/26 15:07:26 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_view_list(t_list lst)
{
	t_elem	*pelem;

	pelem = lst.first;
	while (pelem)
	{
		printf("val list : %d index : %d\n", pelem->value, pelem->index);
		pelem = pelem->next;
	}
}
