/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 12:31:44 by akastler          #+#    #+#             */
/*   Updated: 2022/12/06 13:54:12 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//debut partie puthexa pointeur

int	ft_puthexa_p2(unsigned long n)
{
	char	*b;
	int		len;
	int		a;
	int		temp;

	b = "0123456789abcdef";
	a = n % 16;
	len = 0;
	if (n >= 16)
	{
		len += ft_puthexa_p2(n / 16);
		a = n % 16;
		n = n / 16;
	}
	temp = ft_putchar(b[a]);
	if (temp == -1)
		return (-1);
	else
	{
		len += temp;
		temp = 0;
	}
	return (len);
}

int	ft_puthexa_p(unsigned long n)
{
	int	i;
	int	temp;

	temp = ft_putstr("0x");
	if (temp == -1)
		return (-1);
	else
	{
		i = temp;
		temp = 0;
	}
	if (!n)
	{
		i += ft_putchar('0');
		return (i);
	}
	else
		i += ft_puthexa_p2(n);
	return (i);
}
//fin partie puthexa pointeur
//debut partie puthexa basique

static int	ft_puthexa_fin(char *b, int a)
{
	int	temp;
	int	len;

	temp = ft_putchar(b[a]);
	len = 0;
	if (temp == -1)
		return (-1);
	else
	{
		len += temp;
		temp = 0;
	}
	return (len);
}

static char	*ft_choosemaj(int maj)
{
	char	*b;

	if (maj == 1)
		b = "0123456789ABCDEF";
	else
		b = "0123456789abcdef";
	return (b);
}

int	ft_puthexa(unsigned int n, int maj)
{
	char	*b;
	int		a;
	int		len;
	int		temp;

	len = 0;
	b = ft_choosemaj(maj);
	a = n % 16;
	if (n >= 16)
	{
		len = ft_puthexa(n / 16, maj);
		if (len == -1)
			return (-1);
		a = n % 16;
	}
	temp = ft_puthexa_fin(b, a);
	if (temp == -1)
		return (-1);
	return (len + temp);
}
//fin partie puthexa basique