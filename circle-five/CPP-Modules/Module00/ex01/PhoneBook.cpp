/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:45:31 by akastler          #+#    #+#             */
/*   Updated: 2023/09/11 15:54:32 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(int argc, char **argv)
{
	std::string		input;
	PhoneBook	book;
	int i = 0;

	(void)argv;
	if (argc > 1)
	{
		std::cout << "Please remove arguments" << std::endl;
		return (0);
	}
	else
	{
		while(1)
		{
			if (i == 0){
				std::system("clear"); i++;}
            std::cout << "+--------------------------------------------+" << std::endl;
            std::cout << "|    _____     _        _____                |" << std::endl;
            std::cout << "|   |     |___|_|___   |     |___ ___ _ _    |" << std::endl;
            std::cout << "|   | | | | .'| |   |  | | | | -_|   | | |   |" << std::endl;
            std::cout << "|   |_|_|_|__,|_|_|_|  |_|_|_|___|_|_|___|   |" << std::endl;
            std::cout << "+--------------------------------------------+" << std::endl;
			std::cout << "|  Available commands : ADD | SEARCH | EXIT  |" << std::endl;
			std::cout << "+--------------------------------------------+" << std::endl << ">> ";
			std::getline(std::cin, input);
			if (input.empty() || input == "EXIT") {
                book.ExitPhone();
            }
			else if (input == "ADD")
				book.AddContact();
			else if (input == "SEARCH")
			{
                std::system("clear");
                book.PrintContact();
			}
			else
			{
				std::system("clear");
                std::cout << "+";
                for (int i = 0; i < (int)input.length() + 22; i++)
                    std::cout << "-";
                std::cout << "+" << std::endl;
				std::cout << "| Unknown command : \'" << input << "\' |" << std::endl; //21
                std::cout << "+";
                for (int i = 0; i < (int)input.length() + 22; i++)
                    std::cout << "-";
                std::cout << "+" << std::endl;
			}
		}
	}
}