/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:10:19 by akastler          #+#    #+#             */
/*   Updated: 2023/10/19 11:47:19 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main()
{
	std::cout << "---[ CREATE TIME ]---" << std::endl;
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	AMateria* tmp;

	std::cout << std::endl << "---[ ERROR TIME ]---" << std::endl;
	tmp = src->createMateria("y");
	me->equip(tmp);
	me->use(5, *bob);
	me->use(2, *bob);

	std::cout << std::endl << "---[ LEARN TIME ]---" << std::endl;
	AMateria* tmp1 = new Ice();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(tmp1);
	std::cout << std::endl << "---[ EQUIP TIME ]---" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("test");
	// me->equip(tmp);

	std::cout << std::endl << "---[ USE TIME ]---" << std::endl;
	me->use(2, *bob);
	me->use(3, *bob);

	std::cout << std::endl << "---[ DELETE TIME ]---" << std::endl;
	delete bob;
	delete me;
	delete src;
	delete tmp1;
	delete tmp;
	return 0;
}