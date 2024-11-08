/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 08:32:02 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 11:28:59 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		Fixed _x;
		Fixed _y;
	public:
		Point();
		Point(const Point &src);
		Point(const float x, const float y );
		~Point();

		Point &operator=(const Point &rhs);

		Fixed getX( void ) const;
		Fixed getY( void ) const;
};

bool                bsp( Point const a, Point const b, Point const c, Point const point );

#endif