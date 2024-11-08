/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:17:36 by akastler          #+#    #+#             */
/*   Updated: 2023/09/29 14:14:53 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.class.hpp"

Ice::Ice() {
	this->_type = "ice";
	this->equiped = false;
	return ;
}

Ice::Ice(Ice const & src){
	*this = src;
	return ;
}

Ice::~Ice() {
	_type = "";
	this->equiped = true;
	return ;
}

Ice &Ice::operator=(Ice const &ice) {
	if (this != &ice){
		this->_type = ice._type;
		this->equiped = ice.equiped;
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
	return ;
}