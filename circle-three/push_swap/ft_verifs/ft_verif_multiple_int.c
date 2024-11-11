/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_multiple_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:10:18 by akastler          #+#    #+#             */
/*   Updated: 2023/01/25 16:18:56 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_verif_multiple_int(char *str)
{
	if (ft_strchr(str, 9))
		return (1);
	else if (ft_strchr(str, 10))
		return (1);
	else if (ft_strchr(str, 11))
		return (1);
	else if (ft_strchr(str, 12))
		return (1);
	else if (ft_strchr(str, 13))
		return (1);
	else if (ft_strchr(str, 32))
		return (1);
	else
		return (0);
}
