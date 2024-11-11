/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:39:45 by akastler          #+#    #+#             */
/*   Updated: 2023/01/28 14:43:23 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_init_radix(t_vars_radix *radix, t_list *lst)
{
	radix->pile_b = malloc(sizeof(t_list));
	ft_init(radix->pile_b);
	radix->decal = 0;
	radix->rota = 0;
	radix->tl = ft_len_lst(lst);
}

void	ft_sort_min(t_list *lst)
{
	if (ft_len_lst(lst) == 2)
	{
		if (lst->first->index > lst->first->next->index)
			ft_swap_a(lst);
	}
	else
	{
		if (lst->first->index > lst->first->next->index)
			ft_swap_a(lst);
		if (lst->last->index < lst->last->prev->index)
		{
			ft_reverse_rotate_a(lst);
			if (lst->first->index > lst->first->next->index)
				ft_swap_a(lst);
		}
	}
}

static void	ft_radix_sort(t_list *lst)
{
	t_vars_radix	radix;

	ft_init_radix(&radix, lst);
	while (radix.decal < lst->max_decal)
	{
		while (radix.rota != ft_len_lst(lst))
		{
			if (((lst->first->index >> radix.decal) & 1) == 0)
				push_b(lst, radix.pile_b);
			else
			{
				ft_rotate_a(lst);
				radix.rota++;
			}
			if (ft_list_sorted(lst) == 1)
				break ;
		}
		while (radix.pile_b->first)
			push_a(radix.pile_b, lst);
		radix.rota = 0;
		radix.decal++;
		if (ft_list_sorted(lst) == 1)
			break ;
	}
	free(radix.pile_b);
}

void	ft_algo(t_list *lst)
{
	ft_indexation(lst);
	if (ft_len_lst(lst) == 1)
		return ;
	else if (ft_list_sorted(lst) == 1)
		return ;
	else if (ft_len_lst(lst) <= 3)
		ft_sort_min(lst);
	else if (ft_len_lst(lst) <= 5)
		ft_sort_mid(lst);
	else
		ft_radix_sort(lst);
}
