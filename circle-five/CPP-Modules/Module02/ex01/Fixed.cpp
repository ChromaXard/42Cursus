/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:48:32 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 11:16:21 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) {
	std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
	return ;
}

Fixed::Fixed(Fixed const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed(int const i) {
	std::cout << "Int constructor called" << std::endl;
	this->_raw = i << this->_bits;
	return ;
}

Fixed::Fixed(float const f) {
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(f * (1 << this->_bits));
	return ;
}

Fixed &Fixed::operator=(Fixed const & copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &copy)
		return (*this);
	this->_raw = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
	return ;
}

void Fixed::setRawBits(int const raw) {
	this->_raw = raw;
	return ;
}

int Fixed::getRawBits(void) const {
	return (this->_raw);
}

int Fixed::toInt(void) const {
	return (this->_raw >> this->_bits);
}

float Fixed::toFloat(void) const {
	return ((float)this->_raw / (float)(1 << this->_bits));
}
