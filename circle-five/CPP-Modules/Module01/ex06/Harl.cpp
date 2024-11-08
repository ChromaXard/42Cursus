/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:57:43 by akastler          #+#    #+#             */
/*   Updated: 2023/09/01 11:27:50 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "Harl created" << std::endl;
	return ;
}

Harl::~Harl(void)
{
	std::cout << "Harl killed" << std::endl;
	return ;
}

void Harl::debug(void)
{
	std::cout << "---[ DEBUG ]---" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger." << std::endl;
	std::cout << "I really do !" << std::endl;
}

void Harl::info(void)
{
	std::cout << "---[ INFO ]---" << std::endl;
	std::cout<< "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "---[ WARNING ]---" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "---[ ERROR ]---" << std::endl;
	std::cout << "This is unacceptable ! I want to talk to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
	int i = 0;
	std::string level_tab[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	while(i < 4)
	{
		if (level == level_tab[i])
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout << "---[ INVALID ]---" << std::endl;
			break;
	}
}