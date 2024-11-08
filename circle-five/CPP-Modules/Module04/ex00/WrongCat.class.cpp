/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:19:01 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 18:02:41 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.class.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
	std::cout << "Default WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & src) {
	std::cout << "Copy WrongCat constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat() {
	std::cout << "Default WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

void WrongCat::makeSound(void) const {
	std::cout << "wrong cat-->" << this->_type << ": * wrong meow *" << std::endl;
}