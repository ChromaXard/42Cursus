/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:57:45 by akastler          #+#    #+#             */
/*   Updated: 2023/04/05 15:10:03 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prct(const char *strbase, va_list args, int i)
{
	int	len;

	len = 0;
	if (strbase[i] == 'c')
		len = ft_putchar(va_arg(args, int));
	else if (strbase[i] == 's')
		len = ft_putstr(va_arg(args, char *));
	else if (strbase[i] == 'd' || strbase[i] == 'i')
		len = ft_putnbr(va_arg(args, int));
	else if (strbase[i] == 'u')
		len = ft_putunbr(va_arg(args, unsigned int));
	else if (strbase[i] == 'x')
		len = ft_puthexa(va_arg(args, unsigned int), 2);
	else if (strbase[i] == 'X')
		len = ft_puthexa(va_arg(args, unsigned int), 1);
	else if (strbase[i] == 'p')
		len += ft_puthexa_p(va_arg(args, unsigned long));
	else if (strbase[i] == '%')
		len = ft_putchar('%');
	return (len);
}

static int	ft_format(const char *strbase, int i)
{
	if (strbase[i + 1] == 'c' || strbase[i + 1] == 's' || strbase[i + 1] == 'p'
		|| strbase[i + 1] == 'd' || strbase[i + 1] == 'i' || strbase[i + 1]
		== 'u' || strbase[i + 1] == 'x' || strbase[i + 1] == 'X'
		|| strbase[i + 1] == '%')
		return (1);
	return (0);
}

static int	ft_firstwhile(const char *strbase, va_list args, int i, int tl)
{
	int	temp;

	while (strbase[i])
	{
		temp = 0;
		if (strbase[i] == '%' && ft_format(strbase, i) == 1)
		{
			i++;
			temp += ft_prct(strbase, args, i++);
		}
		else
			temp += ft_putchar(strbase[i++]);
		if (temp >= 0)
			tl += temp;
		else
			return (-1);
	}
	return (tl);
}

int	ft_printf(const char *strbase, ...)
{
	va_list	args;
	int		tl;
	int		i;

	tl = -1;
	i = 0;
	va_start(args, strbase);
	if (strbase)
		tl = 0;
	tl = ft_firstwhile(strbase, args, i, tl);
	va_end(args);
	return (tl);
}
