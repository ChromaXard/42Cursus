/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deltop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:53:17 by akastler          #+#    #+#             */
/*   Updated: 2023/01/25 16:59:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_deltop(t_list *lst)
{
	t_elem	*temp;

	temp = lst->first;
	if (!temp)
	{
		ft_clear_list(lst);
		free(lst);
		return (-1);
	}
	lst->first = temp->next;
	if (lst->first)
		lst->first->prev = NULL;
	else
		lst->first = NULL;
	return (0);
}
