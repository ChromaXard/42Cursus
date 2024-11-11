/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:42:34 by akastler          #+#    #+#             */
/*   Updated: 2023/01/25 16:44:25 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_clear_list(t_list *lst)
{
	t_elem	*tmp;
	t_elem	*pelem;

	pelem = lst->first;
	while (pelem)
	{
		tmp = pelem;
		pelem = pelem->next;
		free(tmp);
	}
	lst->first = NULL;
	lst->last = NULL;
}
