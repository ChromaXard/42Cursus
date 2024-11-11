/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushbottom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:44:49 by akastler          #+#    #+#             */
/*   Updated: 2023/01/26 13:49:01 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pushbottom(t_list *lst, int val, int index)
{
	t_elem	*nouv;

	nouv = malloc(sizeof(t_elem));
	nouv->value = val;
	nouv->index = index;
	nouv->prev = lst->last;
	nouv->next = NULL;
	if (lst->last)
		lst->last->next = nouv;
	else
		lst->first = nouv;
	lst->last = nouv;
}
