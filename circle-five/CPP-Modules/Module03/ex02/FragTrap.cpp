/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:31:22 by akastler          #+#    #+#             */
/*   Updated: 2023/09/23 08:37:00 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap Default Constructor called" << std::endl;
    this->_name = "FragTrap";
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return ;
}

FragTrap::FragTrap(std::string name) {
    std::cout << "FragTrap Parameter Constructor called" << std::endl;
    this->_name = name;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    return ;
}

FragTrap::FragTrap(FragTrap const &src) {
    std::cout << "FragTrap Copy Constructor called" << std::endl;
    *this = src;
    return ;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
    return ;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {
    if (this != &rhs)
    {
        this->_name = rhs._name;
        this->_hitPoints = rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return(*this);
}

void FragTrap::highFivesGuys(void) {
    if (this->_hitPoints > 0)
        std::cout << "hey guys ! Anyone up for a high five ?" << std::endl;
    else
        std::cout << "FragTrap named " << this->_name << " is dead, he can't do that" << std::endl;
    return ;
}