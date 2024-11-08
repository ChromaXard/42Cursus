/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 11:50:10 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 16:02:51 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.class.hpp"

Cat::Cat(void){
	std::cout << "Default cat constructor" << std::endl;
	type = "Cat";
}

Cat::Cat(Cat const &src){
	std::cout << "Copy cat constructor" << std::endl;
	*this = src;
}

Cat::~Cat(void){
	std::cout << "Default cat destructor" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs){
	if (this != &rhs)
	{
		this->type = rhs.type;
	}
	return (*this);
}

void Cat::makeSound(void) const {
	std::cout << this->type << ": meow" << std::endl;
}