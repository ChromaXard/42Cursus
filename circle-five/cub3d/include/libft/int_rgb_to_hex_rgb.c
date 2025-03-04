/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_rgb_to_hex_rgb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:30:38 by aherrman          #+#    #+#             */
/*   Updated: 2024/01/22 10:22:45 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
