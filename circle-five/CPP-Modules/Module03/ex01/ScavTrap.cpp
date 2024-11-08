/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:53:43 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 12:39:57 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
    std::cout << "ScavTrap Default Constructor called" << std::endl;
    this->_name = "ScavTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(std::string name) {
    std::cout << "ScavTrap Parameter Constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    return ;
}

ScavTrap::ScavTrap(ScavTrap const &src) {
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
    *this = src;
    return ;
}


ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
    return ;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return (*this);
}

void ScavTrap::guardGate() {
    if (this->_hitPoints == 0)
    {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot enter in Gate keeper mode" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->_name << " has entered in Gate keeper mode" << std::endl;
    return ;
}

void ScavTrap::attack(std::string const &target) {
    if (this->_hitPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " is dead and cannot attack" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0) {
        std::cout << "ScavTrap " << this->_name << " has no energy left to attack!" << std::endl;
        return ;
    }
    std::cout << "ScavTrap named " << this->_name << " attacks " << target << ", and cause " << this->_attackDamage << " points of damage in one hit!" << std::endl;
    return ;
}