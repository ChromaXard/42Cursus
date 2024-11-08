/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:21:07 by akastler          #+#    #+#             */
/*   Updated: 2023/09/11 13:06:10 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void){
    ScavTrap    scav("Scav_traptest");
    std::cout << std::endl;
    scav.attack("target");
    scav.guardGate();
    scav.takeDamage(10);
    scav.beRepaired(10);
    std::cout << std::endl << std::endl;
    ClapTrap    clap("Clap_traptest");
    std::cout << std::endl;
    clap.attack("target");
    clap.takeDamage(9);
    clap.beRepaired(10);
    std::cout << std::endl;
    return (0);
}