/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:05:56 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 15:40:14 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.class.hpp"

Animal::Animal(void){
	std::cout << "Default animal constructor" << std::endl;
	type = "Animal";
}

Animal::Animal(std::string type){
	std::cout << "Param animal constructor" << std::endl;
	this->type = type;
}

Animal::Animal(Animal const &src){
	std::cout << "Copy animal constructor" << std::endl;
	*this = src;
}

Animal::~Animal(void){
	std::cout << "Default animal destructor" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs){
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void Animal::makeSound(void) const {
	std::cout << this->type << ": * nothing *" << std::endl;
}

std::string Animal::getType(void) const {
	return (this->type);
}
