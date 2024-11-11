/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushtop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:36:57 by akastler          #+#    #+#             */
/*   Updated: 2023/01/25 16:59:32 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pushtop(t_list *lst, int val, int index)
{
	t_elem	*nouv;

	nouv = malloc(sizeof(t_elem));
	if (!nouv)
	{
		ft_clear_list(lst);
		free(lst);
	}
	nouv->value = val;
	nouv->index = index;
	nouv->next = lst->first;
	nouv->prev = NULL;
	if (lst->first)
		lst->first->prev = nouv;
	else
		lst->last = nouv;
	lst->first = nouv;
}
