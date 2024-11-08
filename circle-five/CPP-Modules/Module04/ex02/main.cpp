/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:05:29 by akastler          #+#    #+#             */
/*   Updated: 2023/10/19 11:22:27 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	//Impossible to create an instance of an abstract class
	//Animal *animal = new Animal();
	//main of the subject
	{
		std::cout << "----- creating animals -----" << std::endl;
		// const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << std::endl << "----- call to getType func -----" << std::endl;
		// meta->getType();
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		std::cout << std::endl << "----- call to makeSound func -----" << std::endl;
		i->makeSound();
		j->makeSound();
		// meta->makeSound();
		std::cout << std::endl << "----- deleting animals -----" << std::endl;
		// delete meta;
		delete i;
		delete j;
	}
	//my main
	std::cout << std::endl << "second part" << std::endl;
	{
		std::cout << "----- creating animals -----" << std::endl;
		const Animal* animals[2] = {new Dog(), new Cat()};
		std::cout << std::endl << "----- call to getType and makeSound funcs -----" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			std::cout << animals[i]->getType() << " " << std::endl;
			animals[i]->makeSound();
		}
		std::cout << std::endl << "----- deleting animals -----" << std::endl;
		for (int i = 0; i < 2; i++)
			delete animals[i];
		std::cout << std::endl << "----- creating wrong animals -----" << std::endl;
		const WrongAnimal* wrongAnimals[2] = {new WrongAnimal(), new WrongCat()};
		std::cout << std::endl << "----- call to getType and makeSound funcs -----" << std::endl;
		for (int i = 0; i < 2; i++)
		{
			std::cout << wrongAnimals[i]->getType() << " " << std::endl;
			wrongAnimals[i]->makeSound();
		}
		std::cout << std::endl << "----- deleting wrong animals -----" << std::endl;
		for (int i = 0; i < 2; i++)
			delete wrongAnimals[i];
	}
	{
		std::cout << std::endl << "----- test to see if copy is a deep copy ----- " << std::endl;
		Dog dog;
		{
			std::cout << std::endl << "----- creating a copy of dog -----" << std::endl;
			Dog copy(dog);
			std::cout << std::endl << "----- deleting copy -----" << std::endl;
		}
	}
}