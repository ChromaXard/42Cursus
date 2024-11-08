/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:50:10 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 18:08:04 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void){
	std::cout << "Default cat constructor" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(Cat const &src){
	std::cout << "Copy cat constructor" << std::endl;
	*this = src;
}

Cat::~Cat(void){
	std::cout << "Default cat destructor" << std::endl;
	delete _brain;
}

Cat &Cat::operator=(Cat const &rhs){
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << this->type << ": meow" << std::endl;
}