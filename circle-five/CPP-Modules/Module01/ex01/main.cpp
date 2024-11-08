/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:50:34 by akastler          #+#    #+#             */
/*   Updated: 2023/09/15 09:05:33 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie master;
	master.setName("master");
	std::cout << "master created" << std::endl << std::endl;
	Zombie *Zombie2;
	Zombie *Zombie = master.zombieHorde(7, "Zombie");
	for (int i = 0; i < 7; i++)
		Zombie[i].announce();
	delete [] Zombie;
	std::cout << std::endl << "Second wave of zombies" << std::endl;
	Zombie2 = master.zombieHorde(5, "Zombie2");
	for (int i = 0; i < 5; i++)
		Zombie2[i].announce();
	delete [] Zombie2;
	std::cout << std::endl;
	return (0);
}