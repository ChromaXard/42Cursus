/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_line_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 13:30:32 by event             #+#    #+#             */
/*   Updated: 2023/04/03 09:07:34 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes.h"

char	*ft_get_line_map(int fd)
{
	char	*str;
	char	*final;
	char	*temp;

	str = get_next_line(fd);
	final = NULL;
	while (str)
	{
		if (final)
		{
			temp = final;
			final = ft_strjoin(final, str);
			free(temp);
		}
		else
			final = ft_strjoin("", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (final);
}
