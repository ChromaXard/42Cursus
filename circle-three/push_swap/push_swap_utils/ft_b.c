/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_b.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:21:50 by akastler          #+#    #+#             */
/*   Updated: 2023/01/27 13:28:49 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_b(t_list *pile_a, t_list *pile_b)
{
	t_elem	*elem;

	write(1, "pb\n", 3);
	elem = pile_a->first;
	ft_pushtop(pile_b, elem->value, elem->index);
	ft_deltop(pile_a);
	free(elem);
}
