/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:48:32 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 11:27:57 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
/*constructeurs*/
Fixed::Fixed(void) {
	this->_raw = 0;
	return ;
}

Fixed::Fixed(Fixed const & src) {
	*this = src;
	return ;
}

Fixed::Fixed(int const i) {
	this->_raw = i << this->_bits;
	return ;
}

Fixed::Fixed(float const f) {
	this->_raw = roundf(f * (1 << this->_bits));
	return ;
}

/*------surcharge d'operateurs------*/
Fixed &Fixed::operator=(Fixed const & copy) {
	if (this == &copy)
		return (*this);
	this->_raw = copy.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

Fixed Fixed::operator+(Fixed const & rhs) const {
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed Fixed::operator-(Fixed const & rhs) const {
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed Fixed::operator*(Fixed const & rhs) const {
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed Fixed::operator/(Fixed const & rhs) const {
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed& Fixed::operator++(void) {
	this->_raw++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed& Fixed::operator--(void) {
	this->_raw--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

bool Fixed::operator>(Fixed const & rhs) const {
	if (this->toFloat() > rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const & rhs) const {
	if (this->toFloat() < rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const & rhs) const {
	if (this->toFloat() >= rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator<=(Fixed const & rhs) const {
	if (this->toFloat() <= rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const & rhs) const {
	if (this->toFloat() == rhs.toFloat())
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const & rhs) const {
	if (this->toFloat() != rhs.toFloat())
		return (true);
	return (false);
}

/*destructeur*/
Fixed::~Fixed(void) {
	return ;
}

/*fonctions*/
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

Fixed &Fixed::min(Fixed & a, Fixed & b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a > b)
		return(a);
	return(b);
}

const Fixed &Fixed::min(Fixed const & a, Fixed const & b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a > b)
		return(a);
	return(b);
}
