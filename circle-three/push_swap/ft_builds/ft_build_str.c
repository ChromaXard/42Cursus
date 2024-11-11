/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:33:46 by akastler          #+#    #+#             */
/*   Updated: 2023/01/28 18:19:19 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_findstart(char *str)
{
	int	start;

	start = 0;
	if (str[start + 1] != 0)
	{
		if (str[start] == ' ')
			while (str[start] == ' ')
				start++;
		while ((str[start] >= '0' && str[start] <= '9') || str[start] == '-'
			|| str[start] == '+')
			start++;
	}
	else
		return (start + 1);
	return (start);
}

int	ft_build_str(char *str, t_list *lst)
{
	int	start;

	start = 0;
	while (str[start] != '\0')
	{
		if (ft_verif_int(str + start) == -1)
			return (-1);
		else if (str[start + 1] != '\0')
		{
			if (lst->last)
				ft_pushbottom(lst, ft_atoi(str + start), lst->last->index + 1);
			else
				ft_pushbottom(lst, ft_atoi(str + start), 0);
		}
		start += ft_findstart(str + start);
	}
	return (0);
}
