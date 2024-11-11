/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:57:51 by akastler          #+#    #+#             */
/*   Updated: 2023/01/26 13:37:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_verif_int(char *str)
{
	int		i;
	int		j;
	char	*test;

	i = 0;
	j = 0;
	test = ft_itoa(ft_atoi(str));
	if (str[i] == ' ' || str[i] == '+' || (str[i] >= 9 && str[i] <= 13))
		while (str[i] == ' ' || str[i] == '+' || (str[i] >= 9 && str[i] <= 13))
			i++;
	while (str[i] != ' ' && str[i] != '\0')
	{
		if (str[i] != test[j])
		{
			free(test);
			return (-1);
		}
		i++;
		j++;
	}
	free(test);
	return (0);
}
