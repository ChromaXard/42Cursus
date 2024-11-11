/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_indexation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:43:43 by akastler          #+#    #+#             */
/*   Updated: 2023/02/01 08:44:14 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_sort_tab(int *tab, int index)
{
	int	pass;
	int	perm;
	int	whl;
	int	temp;

	pass = 0;
	perm = 1;
	while (perm)
	{
		perm = 0;
		pass++;
		whl = 0;
		while (whl < index - pass)
		{
			if (tab[whl] > tab[whl + 1])
			{
				perm = 1;
				temp = tab[whl];
				tab[whl] = tab[whl + 1];
				tab[whl + 1] = temp;
			}
			whl++;
		}
	}
}

static int	ft_give_max_decal(int i)
{
	int	max;

	max = 1;
	if (i > 1)
		max += ft_give_max_decal(i / 2);
	return (max);
}

static int	ft_cpy_val_list(t_list *list, int *tab)
{
	int		index;
	t_elem	*iter;

	index = 0;
	iter = list->first;
	while (index < list->last->index + 1)
	{
		tab[index++] = iter->value;
		iter = iter->next;
	}
	return (index);
}

void	ft_indexation(t_list *lst)
{
	int		*tab;
	t_elem	*iter;
	int		i;
	int		index;

	tab = malloc(sizeof(int) * ft_len_lst(lst));
	iter = lst->first;
	i = 0;
	index = ft_cpy_val_list(lst, tab);
	ft_sort_tab(tab, index);
	while (iter)
	{
		i = 0;
		while (i < index)
		{
			if (tab[i] == iter->value)
				iter->index = i;
			i++;
		}
		iter = iter->next;
	}
	lst->max_decal = ft_give_max_decal(i);
	free(tab);
	free(iter);
}
