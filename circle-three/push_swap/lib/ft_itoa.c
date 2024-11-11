/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:10:49 by akastler          #+#    #+#             */
/*   Updated: 2023/01/28 14:36:38 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = '\0';
		i++;
	}
}

static void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*point;

	point = malloc(count * size);
	if (!point)
		return (0);
	ft_bzero(point, count * size);
	return (point);
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
