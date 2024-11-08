/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:38:16 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 11:31:03 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float vector_product(Point const p1 , Point const p2, Point const p3)
{
	return ((p2.getX().toFloat() - p1.getX().toFloat()) * (p3.getY().toFloat() - p1.getY().toFloat())
			- (p3.getX().toFloat() - p1.getX().toFloat()) * (p2.getY().toFloat() - p1.getY().toFloat()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float d[3];
	bool neg_or_pos[2];

	d[0] = vector_product(point, a, b);
	d[1] = vector_product(point, b, c);
	d[2] = vector_product(point, c, a);

	neg_or_pos[0] = (d[0] < 0) || (d[1] < 0) || (d[2] < 0);
	neg_or_pos[1] = (d[0] > 0) || (d[1] > 0) || (d[2] > 0);

	return !(neg_or_pos[0] && neg_or_pos[1]);
}