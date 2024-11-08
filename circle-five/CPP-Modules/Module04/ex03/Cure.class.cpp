/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:38:43 by akastler          #+#    #+#             */
/*   Updated: 2023/09/29 14:13:24 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cure.class.hpp"

Cure::Cure() {
	this->_type = "cure";
	this->equiped = false;
	return ;
}

Cure::Cure(Cure const & src){
	*this = src;
	return ;
}

Cure::~Cure() {
	_type = "";
	return ;
}

Cure &Cure::operator=(Cure const &Cure) {
	if (this != &Cure){
		this->_type = Cure._type;
		this->equiped = Cure.equiped;
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
	return ;
}