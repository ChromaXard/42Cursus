/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:22:50 by akastler          #+#    #+#             */
/*   Updated: 2023/09/15 09:18:10 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA named " << name << " created" << std::endl;
	return ;
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA named " << this->_name << " killed" << std::endl;
	return ;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->_weapon = weapon;
}