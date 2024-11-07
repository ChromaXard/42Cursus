/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:56:23 by akastler          #+#    #+#             */
/*   Updated: 2022/11/11 09:30:52 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calclonnb(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				i;
	char			*str;
	unsigned int	nbr;

	i = ft_calclonnb(n);
	str = ft_calloc((ft_calclonnb(n) + 1), sizeof(char));
	i = i - 1;
	if (n < 0)
		nbr = n * -1;
	else
		nbr = n;
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (nbr > 0)
	{
		str[i--] = 48 + (nbr % 10);
		nbr = nbr / 10;
	}
	return (str);
}
