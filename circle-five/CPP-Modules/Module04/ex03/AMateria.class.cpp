/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:32:47 by akastler          #+#    #+#             */
/*   Updated: 2023/09/23 12:38:08 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.class.hpp"

AMateria::AMateria(std::string const & type) {
	if (type.empty() == false && type != "")
		this->_type = type;
	else
		this->_type = "default";
	return ;
}

AMateria::AMateria() : _type("default") {
	return ;
}

AMateria::AMateria(AMateria const & src) {
	*this = src;
	return ;
}

AMateria::~AMateria() {
	_type = "";
	return ;
}

AMateria & AMateria::operator=(AMateria const & rhs) {
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

std::string const &AMateria::getType() const {
	return (this->_type);
}

void AMateria::use(ICharacter& target) {
	std::cout << "* shoots an Materia bolt at " << target.getName() << " *" << std::endl;
	return ;
}