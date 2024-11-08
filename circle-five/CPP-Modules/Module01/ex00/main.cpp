/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 11:48:33 by akastler          #+#    #+#             */
/*   Updated: 2023/09/15 08:50:45 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>


int main(void)
{
    Zombie master("master");
    std::cout << "master is created" << std::endl << std::endl;
    std::cout << "Zombie with function \"newZombie\"" << std::endl;
    Zombie *zombie[2];
    zombie[1] = master.newZombie("z");
    zombie[0] = master.newZombie("y");
    zombie[1]->announce();
    zombie[0]->announce();
    std::cout << std::endl << "call to delete func" << std::endl;
    delete zombie[0];
    delete zombie[1];
    std::cout << std::endl;
    std::cout << "Zombie with function randomChump" << std::endl;
    master.randomChump("x");
    master.randomChump("w");
    master.randomChump("v");
    std::cout << std::endl;
    return (0);
}