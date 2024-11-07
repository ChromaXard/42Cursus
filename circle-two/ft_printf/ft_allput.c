/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:36:03 by akastler          #+#    #+#             */
/*   Updated: 2022/12/07 09:50:39 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	int	i;

	i = 0;
	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *str)
{
	int	i;
	int	temp;

	i = 0;
	if (str == NULL)
		i += ft_putstr("(null)");
	else
	{
		while (str[i])
		{
			temp = ft_putchar(str[i]);
			if (temp == -1)
				return (-1);
			else
			{
				i += temp;
				temp = 0;
			}
		}
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;
	int	temp;

	i = 0;
	if (n > 9)
	{
		temp = ft_putunbr(n / 10);
		if (temp == -1)
			return (-1);
		else
			i += temp;
		i += ft_putunbr(n % 10);
	}
	else
	{
		i += ft_putchar(n + '0');
	}
	return (i);
}
