/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 08:43:47 by akastler          #+#    #+#             */
/*   Updated: 2022/12/07 09:44:43 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_intmin(void)
{
	int	temp;
	int	i;

	i = 0;
	temp = ft_putstr("-2");
	if (temp == -1)
		return (-1);
	else
		i += temp;
	i += ft_putnbr(147483648);
	return (i);
}

static int	ft_putnbr_underzero(int n)
{
	int	temp;
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		temp = ft_putnbr_intmin();
		if (temp == -1)
			return (-1);
		else
			i += temp;
	}
	else
	{
		temp = ft_putchar('-');
		if (temp == -1)
			return (-1);
		else
			i += temp;
		n = -n;
		i += ft_putnbr(n);
	}
	return (i);
}

static int	ft_putnbr_overnine(int n)
{
	int	temp;
	int	i;

	i = 0;
	temp = ft_putnbr(n / 10);
	if (temp == -1)
		return (-1);
	else
		i += temp;
	i += ft_putnbr(n % 10);
	return (i);
}

int	ft_putnbr(int n)
{
	int	j;
	int	temp;

	j = 0;
	if (n < 0)
	{
		temp = ft_putnbr_underzero(n);
		if (temp == -1)
			return (-1);
		else
			j += temp;
	}
	else if (n > 9)
	{
		temp = ft_putnbr_overnine(n);
		if (temp == -1)
			return (-1);
		else
			j += temp;
	}
	else
		j += ft_putchar(n + '0');
	return (j);
}
