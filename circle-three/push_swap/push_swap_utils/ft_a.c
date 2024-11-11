/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:20:44 by akastler          #+#    #+#             */
/*   Updated: 2023/01/27 15:26:15 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_a(t_list *pile_b, t_list *pile_a)
{
	t_elem	*elem;

	write(1, "pa\n", 3);
	elem = pile_b->first;
	ft_pushtop(pile_a, elem->value, elem->index);
	ft_deltop(pile_b);
	free(elem);
}

void	ft_rotate_a(t_list *list)
{
	write(1, "ra\n", 3);
	list->last->next = list->first;
	list->first = list->first->next;
	list->first->prev = NULL;
	list->last->next->prev = list->last;
	list->last = list->last->next;
	list->last->next = NULL;
}

void	ft_reverse_rotate_a(t_list *lst)
{
	write(1, "rra\n", 4);
	lst->last = lst->last->prev;
	lst->first->prev = lst->last->next;
	lst->last->next = NULL;
	lst->first->prev->next = lst->first;
	lst->first->prev->prev = NULL;
	lst->first = lst->first->prev;
}

void	ft_swap_a(t_list *lst)
{
	write(1, "sa\n", 3);
	if (ft_len_lst(lst) == 2)
	{
		lst->first = lst->first->next;
		lst->first->next = lst->first->prev;
		lst->last = lst->first->prev;
		lst->first->prev = NULL;
		lst->last->prev = lst->first;
		lst->last->next = NULL;
	}
	else
	{
		lst->first->prev = lst->first->next;
		lst->first->next = lst->first->next->next;
		lst->first = lst->first->prev;
		lst->first->next = lst->first->prev;
		lst->first->prev = NULL;
		lst->first->next->next->prev = lst->first->next;
	}
}
