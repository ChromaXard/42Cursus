/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:23:08 by akastler          #+#    #+#             */
/*   Updated: 2023/08/30 16:29:26 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "Weapon " << type << " created" << std::endl;
	return ;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon " << Weapon::_type << " destroyed" << std::endl;
	return;
}

std::string const &Weapon::getType(void) const {
	return(Weapon::_type);
}

void    Weapon::setType(std::string type) {
	Weapon::_type = type;
}