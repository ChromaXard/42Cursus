/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:58 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 12:35:04 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap_default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "ClapTrap parameter constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
    return ;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    if (this != &rhs) {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
    return ;
}

void ClapTrap::attack(std::string const &target) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy left to attack!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
    this->_energyPoints -= 1;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "Wait ! ClapTrap " << this->_name << " is already dead, don't attack him again !" << std::endl;
        std::cout << "You're a monster ! *Your attack failed*" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0){
        std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
        this->_hitPoints = 0;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " is dead and cannot repair" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy left to repair!" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points!" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    return ;
}
