/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:38:00 by akastler          #+#    #+#             */
/*   Updated: 2023/02/10 13:44:02 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_lst_inf_3(t_list *lst, t_list *pile_b, int len)
{
	if (len == 5)
	{
		if (lst->first->index <= 1)
			push_b(lst, pile_b);
		else
			ft_rotate_a(lst);
	}
}

static void	ft_sort_4(t_list *lst, t_list *pile_b)
{
	while (ft_len_lst(lst) > 3)
	{
		if (lst->first->index == 0)
			push_b(lst, pile_b);
		else
			ft_rotate_a(lst);
	}
	ft_sort_min(lst);
	push_a(pile_b, lst);
}

void	ft_sort_mid(t_list *lst)
{
	t_list	*pile_b;

	pile_b = malloc(sizeof(t_list));
	ft_init(pile_b);
	if (ft_len_lst(lst) == 5)
	{
		while (ft_len_lst(lst) > 3)
			ft_lst_inf_3(lst, pile_b, 5);
		ft_sort_min(lst);
		while (pile_b->first)
			push_a(pile_b, lst);
		if (lst->first->index > lst->first->next->index)
			ft_swap_a(lst);
	}
	else if (ft_len_lst(lst) == 4)
		ft_sort_4(lst, pile_b);
	else if (ft_len_lst(lst) <= 3)
		ft_sort_min(lst);
	free(pile_b);
}
