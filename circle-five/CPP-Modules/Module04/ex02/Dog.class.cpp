/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:55:40 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 18:11:13 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.class.hpp"

Dog::Dog(void){
	std::cout << "Default Dog constructor" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const &src){
	std::cout << "Copy Dog constructor" << std::endl;
	*this = src;
}

Dog::~Dog(void){
	std::cout << "Default Dog destructor" << std::endl;
	delete _brain;
}

Dog &Dog::operator=(Dog const &rhs){
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Dog::makeSound(void) const {
	std::cout << this->type << ": bark" << std::endl;
}