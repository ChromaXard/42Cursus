/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:39:18 by akastler          #+#    #+#             */
/*   Updated: 2023/10/02 14:23:52 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

MateriaSource::MateriaSource() {
	std::cout << "MateriaSource is in production" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	return ;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	this->_deleteInventory();
	std::cout << "MateriaSource is being copied" << std::endl;
	for (int slot = 0; slot < 4; slot++) {
		if (src._inventory[slot])
			this->_inventory[slot] = src._inventory[slot];
	}
	return ;
}

MateriaSource::~MateriaSource() {
	std::cout << "MateriaSource is being destroyed" << std::endl;
	this->_deleteInventory();
	return ;
}

MateriaSource &MateriaSource::operator=(MateriaSource const &MateriaSource) {
	std::cout << "MateriaSource is being assigned with another MateriaSource" << std::endl;
	if (this != &MateriaSource) {
		this->_deleteInventory();
		for (int slot = 0; slot < 4; slot++) {
			if (MateriaSource._inventory[slot])
				this->_inventory[slot] = MateriaSource._inventory[slot];
		}
	}
	return *this;
}

void MateriaSource::_deleteInventory() {
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]){
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

void MateriaSource::learnMateria(AMateria* materia) {
	if (!materia || materia->equiped) {
		std::cout << "MateriaSource can't learn this" << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (!this->_inventory[i]) {
			materia->equiped = true;
			this->_inventory[i] = materia;
			std::cout << "MateriaSource learned " << materia->getType() << std::endl;
			return ;
		}
	}
	std::cout << "MateriaSource is full" << std::endl;
	return ;
}

AMateria* MateriaSource::createMateria(std::string const &type){
	for(int i = 0; i < 4; i++) {
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			std::cout << "Materia " << type << " exists" << std::endl << "MateriaSource creates a new one" << std::endl;
			AMateria *temp = this->_inventory[i]->clone();
			temp->equiped = false;
			return (temp);
		}
	}
	std::cout << "Materia " << type << " doesn't exist" << std::endl;
	return(NULL);
}
