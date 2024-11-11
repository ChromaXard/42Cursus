/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:57:43 by akastler          #+#    #+#             */
/*   Updated: 2023/01/27 12:00:32 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_len_lst(t_list *lst)
{
	int		i;
	t_elem	*iter;

	i = 0;
	iter = lst->first;
	while (iter)
	{
		iter = iter->next;
		i++;
	}
	return (i);
}
