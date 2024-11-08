/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.class.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:02:42 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 16:16:05 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
	std::cout << "Default WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
	std::cout << "Param WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "Copy WrongAnimal constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Default WrongAnimal destructor called" << std::endl;
}

WrongAnimal &        WrongAnimal::operator=(WrongAnimal const & rhs) {
	if ( this != &rhs )
		this->_type = rhs._type;
	return *this;
}

std::string         WrongAnimal::getType(void) const {
	return this->_type;
}

void                WrongAnimal::makeSound(void) const {
	std::cout << this->_type <<  ": * nothing is wrong *" << std::endl;
}

