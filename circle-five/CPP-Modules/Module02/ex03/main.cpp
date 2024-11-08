/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:46:12 by akastler          #+#    #+#             */
/*   Updated: 2023/09/06 09:18:19 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {
	Point a(2,2);
	Point b(6,2);
	Point c(4,5);
	Point point[5] = {Point(2.1f,2), Point(5,5), Point(4,4.9f), Point(3,3), Point(2,3.5f)};

	std::cout << "Point A" << std::endl << "x = " << a.getX() << " | y = " << a.getY() << std::endl << std::endl;
	std::cout << "Point B" << std::endl << "x = " << b.getX() << " | y = " << b.getY() << std::endl << std::endl;
	std::cout << "Point C" << std::endl << "x = " << c.getX() << " | y = " << c.getY() << std::endl << std::endl;
	for (int i = 0; i < 5; i++)
	{
		std::cout << "point[" << i << "]" << std::endl << "x = " << point[i].getX() << " | y = " << point[i].getY() << std::endl;
		bsp(a, b, c, point[i]) ? std::cout << "in the triangle" << std::endl << std::endl : std::cout << "not in the triangle" << std::endl << std::endl;
	}
}