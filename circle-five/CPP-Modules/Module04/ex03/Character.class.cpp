/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:42:46 by akastler          #+#    #+#             */
/*   Updated: 2023/10/11 14:30:37 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.class.hpp"

Character::Character() : _name("Random") {
	std::cout << "Character named Random created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::Character(std::string name) : _name(name) {
	std::cout << "Character named " << name << " created" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

Character::~Character() {
	this->_deleteInventory();
	std::cout << "Character named " << this->_name << " destroyed" << std::endl;
	return ;
}

Character::Character(Character const & src){
	for (int slot = 0; slot < 4; slot++) {
		if (src._inventory[slot])
			this->_inventory[slot] = src._inventory[slot]->clone();
	}
	_name = src._name;
	std::cout << "Character named " << this->_name << " copied" << std::endl;
	return ;
}

Character &Character::operator=(Character const &Character) {
	this->_deleteInventory();
	if (this != &Character) {
		for (int slot = 0; slot < 4; slot++) {
			if (Character._inventory[slot])
				this->_inventory[slot] = Character._inventory[slot]->clone();
		}
		this->_name = Character._name;
		std::cout << "Character named " << this->_name << " assigned" << std::endl;
	}
	return (*this);
}

void Character::_deleteInventory() {
	for (int slot = 0; slot < 4; slot++) {
		if (this->_inventory[slot]) {
			delete this->_inventory[slot];
			this->_inventory[slot] = NULL;
		}
	}
}

std::string const & Character::getName() const {
	return (this->_name);
}

void Character::equip(AMateria* m) {
	if (m == NULL)
	{
		std::cout << "Character can't equip this" << std::endl;
		return ;
	}
	if (m->equiped) {
		std::cout << "Character can't equip this" << std::endl;
		return ;
	}
	for (int slot = 0; slot < 4; slot++) {
		if (!this->_inventory[slot]) {
			m->equiped = true;
			this->_inventory[slot] = m;
			std::cout << "Character equiped " << m->getType() << " in slot number " << slot << std::endl;
			return ;
		}
	}
	std::cout << "Character's inventory is full" << std::endl;
	return ;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx > 3) {
		std::cout << "Character can't unequip this" << std::endl;
		return ;
	}
	if (!this->_inventory[idx]) {
		std::cout << "Character Materia slot number " << idx << " is empty" << std::endl;
		return ;
	}
	this->_inventory[idx]->equiped = false;
	this->_inventory[idx] = NULL;
	std::cout << "Character unequiped slot number " << idx << std::endl;
	return ;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3) {
		std::cout << "Character can't use this" << std::endl;
		return ;
	}
	if (!this->_inventory[idx]) {
		std::cout << "Character Materia slot number " << idx << " is empty" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
	return ;
}
