/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:21:07 by akastler          #+#    #+#             */
/*   Updated: 2023/09/26 14:59:13 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void){
    ClapTrap    clap;
    ClapTrap    clap2(clap);
    ClapTrap    clap3("ErrorClap");

    std::cout << std::endl;
    std::cout << "\033[36mtry to attacks :\033[0m" << std::endl;
    clap.attack("target");
    clap2.attack("target9");
    clap3.attack("target8");
    std::cout << std::endl << "\033[36mClapTrap taking damages :\033[0m" << std::endl;
    clap2.takeDamage(9);
    clap3.takeDamage(1);
    clap.takeDamage(5);
    std::cout << std::endl << "\033[36mClapTrap dying and taking damage after death :\033[0m" << std::endl;
    clap.takeDamage(6);
    clap.takeDamage(1);
    
    std::cout << std::endl << "\033[36mClapTrap repairing :\033[0m" << std::endl;
    clap.beRepaired(5);
    clap3.beRepaired(5);
    clap2.beRepaired(1);
    
    std::cout << std::endl;
    return (0);
}