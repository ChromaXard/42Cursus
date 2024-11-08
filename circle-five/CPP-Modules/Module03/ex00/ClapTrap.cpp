/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:20:58 by akastler          #+#    #+#             */
/*   Updated: 2023/09/26 14:57:50 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("ClapTrap_default"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[35mClapTrap default constructor called\033[0m" << std::endl;
    return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
    std::cout << "\033[35mClapTrap parameter constructor called\033[0m" << std::endl;
    return ;
}

ClapTrap::ClapTrap(ClapTrap const &src) {
    std::cout << "\033[35mClapTrap copy constructor called\033[0m" << std::endl;
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
    std::cout << "\033[35mClapTrap destructor called\033[0m" << std::endl;
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
    std::cout << "\033[33mClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!\033[0m" << std::endl;
    this->_energyPoints -= 1;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "\033[31mWait ! ClapTrap " << this->_name << " is already dead, don't attack him again !" << std::endl;
        std::cout << "You're a monster ! *Your attack failed*\033[0m" << std::endl;
        return ;
    }
    std::cout << "\033[31mClapTrap " << this->_name << " takes " << amount << " points of damage!\033[0m" << std::endl;
    this->_hitPoints -= amount;
    if (this->_hitPoints <= 0){
        std::cout << "\033[31mClapTrap " << this->_name << " is dead!\033[0m" << std::endl;
        this->_hitPoints = 0;
    }
    return ;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints == 0) {
        std::cout << "\033[31mClapTrap " << this->_name << " is dead and cannot repair\033[0m" << std::endl;
        return ;
    }
    if (this->_energyPoints == 0) {
        std::cout << "\033[31mClapTrap " << this->_name << " has no energy left to repair!\033[0m" << std::endl;
        return ;
    }
    std::cout << "\033[32mClapTrap " << this->_name << " is repaired for " << amount << " points!\033[0m" << std::endl;
    this->_hitPoints += amount;
    this->_energyPoints -= 1;
    return ;
}
