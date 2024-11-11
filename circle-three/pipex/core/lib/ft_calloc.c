/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:35:19 by event             #+#    #+#             */
/*   Updated: 2023/03/17 15:47:51 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	size_t			i;

	i = 0;
	temp = (unsigned char *)s;
	while (i < n)
	{
		*temp = '\0';
		temp++;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*point;

	point = (unsigned char *)malloc(count * size);
	if (!point)
		return (0);
	if (point)
		ft_bzero(point, count * size);
	return (point);
}
