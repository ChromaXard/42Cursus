/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:54:52 by akastler          #+#    #+#             */
/*   Updated: 2023/09/15 09:01:55 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *Zombie::zombieHorde(int number_of_zombies, std::string name)
{
	Zombie *zombie = new Zombie[number_of_zombies];
	for (int i = 0; i < number_of_zombies; i++)
		zombie[i].setName(name);
	return (zombie);
}