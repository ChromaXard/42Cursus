/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 13:01:48 by akastler          #+#    #+#             */
/*   Updated: 2023/09/11 15:55:18 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::ExitPhone(void)
{
	std::system("clear");
    std::cout << "+--------------+" << std::endl;
    std::cout << "|  Exiting...  |" << std::endl;
    std::cout << "+--------------+" << std::endl;
    for (int i = 0; i < 1000000000; i++)
        ;
    std::system("clear");
    exit(0);
}

int PhoneBook::_VerifyNumber(std::string number)
{
	int i = 0;

	while (number[i])
	{
		if (number[i] < '0' || number[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

std::string PhoneBook::_ReplaceSpace(std::string str){
    int i = 0;

    if (str.length() > 0)
    {
        while(str[i])
        {
            if (str[i] >= 9 && str[i] <= 13)
                str[i] = 32;
            i++;
        }
    }
    return(str);
}

std::string PhoneBook::_TruncStr(std::string str)
{
	std::string temp;

	if (str.length() > 10)
	{
		temp = str.substr(0, 9);
		temp += ".";
		return (temp);
	}
	else
		return (str);
}

void PhoneBook::_PrintAddHeader()
{
    std::cout << "+-------------+" << std::endl;
    std::cout << "| ADD COMMAND +---------------+" << std::endl;
    std::cout << "| Changing contact number : " << this->_AddNumber + 1 << " |" << std::endl;
    std::cout << "+-----------------------------+" << std::endl;
}

void PhoneBook::AddContact(void)
{
	int i = 0;
    std::string temp;

	if (this->_AddNumber >= 8 || this->_AddNumber < 0)
        this->_AddNumber = 0;
    while(1)
	{
		if (i == 0) {
            std::system("clear");
            i++;
            this->_PrintAddHeader();
        }
        std::cout << "First name : ";
        std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
		if (temp.length() == 0){
			std::system("clear");
            this->_PrintAddHeader();
            std::cout << "First name must be at least 1 character" << std::endl;
            continue;
        }
		else{
            this->_Contacts[this->_AddNumber].SetFirstName(this->_ReplaceSpace(temp));
			break;
		}
	}
	i = 0;
	while(1)
	{
		if (i == 0){
			std::system("clear");
            i++;
            this->_PrintAddHeader();
        }
        std::cout << "Last name : ";
		std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
		if (temp.length() == 0){
			std::system("clear");
            this->_PrintAddHeader();
            std::cout << "Last name must be at least 1 character" << std::endl;}
		else
		{
            this->_Contacts[this->_AddNumber].SetLastName(this->_ReplaceSpace(temp));
			break;
		}
	}
	i = 0;
	while(1)
	{
        if (i == 0){
            std::system("clear");
            i++;
            this->_PrintAddHeader();
        }
		std::cout << "Nickname : ";
		std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
		if (temp.length() == 0){
			std::system("clear");
            this->_PrintAddHeader();
            std::cout << "Nickname must be at least 1 character" << std::endl;
        }
		else
		{
            this->_Contacts[this->_AddNumber].SetNickname(this->_ReplaceSpace(temp));
			break;
		}
	}
	i = 0;
	while(1)
	{
        if (i == 0){
            std::system("clear");
            i++;
            this->_PrintAddHeader();
        }
		std::cout << "Phone number : ";
		std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
		if (temp.length() != 10 || this->_VerifyNumber(temp) == 0){
			std::system("clear");
            this->_PrintAddHeader();
            std::cout << "Phone number must be 10 digits" << std::endl;
        }
		else
		{
            this->_Contacts[this->_AddNumber].SetPhoneNumber(this->_ReplaceSpace(temp));
			break;
		}
	}
	i = 0;
	while (1)
	{
        if (i == 0){
            std::system("clear");
            this->_PrintAddHeader();
            i++;
        }
		std::cout << "Darkest secret : ";
		std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
		if (temp.length() == 0){
			std::system("clear");
            this->_PrintAddHeader();
            std::cout << "Darkest secret must be at least 1 character" << std::endl;
        }
		else
		{
            this->_Contacts[this->_AddNumber].SetDarkestSecret(this->_ReplaceSpace(temp));
			break;
		}
	}
	std::system("clear");
	this->_AddNumber += 1;
	if (this->_AddNumber >= 8 || this->_AddNumber < 0)
		this->_AddNumber = 0;
}

void PhoneBook::PrintBook() {
    int i = 0;

    std::cout << "+----------+----------+----------+----------+-+" << std::endl;
    std::cout << "|  _____ _               _____         _    |P|" << std::endl;
    std::cout << "| |  _  | |_ ___ ___ ___| __  |___ ___| |_  |A|" << std::endl;
    std::cout << "| |   __|   | . |   | -_| __ -| . | . | '_| |G|" << std::endl;
    std::cout << "| |__|  |_|_|___|_|_|___|_____|___|___|_,_| |E|" << std::endl;
    std::cout << "+----------+----------+----------+----------+-+" << std::endl;
    std::cout << "|     Index|First name| Last name|  Nickname|1|" << std::endl;
    std::cout << "+----------+----------+----------+----------+-+" << std::endl;
    while (i < 8) {
        if (this->_Contacts[i].GetFirstName().length() == 0)
            break;
        std::cout << "|         " << i + 1 << "|";
        std::cout << std::setw(10) << std::right << this->_TruncStr(this->_Contacts[i].GetFirstName()) << "|";
        std::cout << std::setw(10) << std::right << this->_TruncStr(this->_Contacts[i].GetLastName()) << "|";
        std::cout << std::setw(10) << std::right << this->_TruncStr(this->_Contacts[i].GetNickname()) << "|" << std::endl;
        i++;
    }
    if (i == 0)
        std::cout << "|         No contacts registered yet        |" << std::endl;
    std::cout << "+----------+----------+----------+----------+" << std::endl;
}

void PhoneBook::PrintContact()
{
    std::string temp;

    this->PrintBook();
    if (this->_Contacts[0].GetFirstName().length() == 0){
        std::cout << "press enter to back to main menu" << std::endl;
        std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
        std::system("clear");
        return ;
    }
    else {
    std::cout << "Enter contact index : ";
    int i;
    while (1) {
        std::getline(std::cin, temp);
        if (std::cin.eof())
            this->ExitPhone();
        if (temp.length() == 1 && temp[0] <= '8' && temp[0] > '0') {
            std::system("clear");
            i = std::atoi(&temp[0]);
            i--;
            if (this->_Contacts[i].GetFirstName().length() == 0)
            {
                this->PrintBook();
                std::cout << "Contact number " << i + 1 << " does not exist" << std::endl;
                std::cout << "Enter contact index : ";
            }
            else
                break ;
        }
        else
        {
            std::system("clear");
            this->PrintBook();
            std::cout << "Enter valid contact index : ";
        }
    }
    std::system("clear");
    size_t len = 35;
    {
        if (14 + this->_Contacts[i].GetFirstName().length() > len)
            len = 14 + this->_Contacts[i].GetFirstName().length();
        if (13 + this->_Contacts[i].GetLastName().length() > len)
            len = 13 + this->_Contacts[i].GetLastName().length();
        if (12 + this->_Contacts[i].GetNickname().length() > len)
            len = 12 + this->_Contacts[i].GetNickname().length();
        if (16 + this->_Contacts[i].GetPhoneNumber().length() > len)
            len = 16 + this->_Contacts[i].GetPhoneNumber().length();
        if (18 + this->_Contacts[i].GetDarkestSecret().length() > len)
            len = 18 + this->_Contacts[i].GetDarkestSecret().length();
    }
    std::cout << "+";
    for (size_t j = 0; j < len - 1; j++)
        std::cout << "-";
    std::cout << "+" << std::endl;
    std::cout << "|Informations of contact number : " << i + 1;
    if (35 < len - 1)
        std::cout << std::setw(len - (35 - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;


    std::cout << "|First name : " << this->_Contacts[i].GetFirstName();
    if ((14 + this->_Contacts[i].GetFirstName().length()) < len - 1)
        std::cout << std::setw(len - ((14 + this->_Contacts[i].GetFirstName().length()) - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;


    std::cout << "|Last name : " << this->_Contacts[i].GetLastName();
    if ((13 + this->_Contacts[i].GetLastName().length()) < len - 1)
        std::cout << std::setw(len - ((13 + this->_Contacts[i].GetLastName().length()) - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;


    std::cout << "|Nickname : " << this->_Contacts[i].GetNickname();
    if ((12 + this->_Contacts[i].GetNickname().length()) < len - 1)
        std::cout << std::setw(len - ((12 + this->_Contacts[i].GetNickname().length()) - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;


    std::cout << "|Phone Number : " << this->_Contacts[i].GetPhoneNumber();
    if ((16 + this->_Contacts[i].GetPhoneNumber().length()) < len - 1)
        std::cout << std::setw(len - ((16 + this->_Contacts[i].GetPhoneNumber().length()) - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;


    std::cout << "|Darkest secret : " << this->_Contacts[i].GetDarkestSecret();
    if ((18 + this->_Contacts[i].GetDarkestSecret().length()) < len - 1)
        std::cout << std::setw(len - ((18 + this->_Contacts[i].GetDarkestSecret().length()) - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;


    std::cout << "+";
    for (size_t j = 0; j < len - 1; j++)
        std::cout << "-";
    std::cout << "+" << std::endl;

    
    std::cout << "|press enter to back to main menu";
    if ((33) < len - 1)
        std::cout << std::setw(len - ((33) - 1)) << std::right << "|";
    else
        std::cout << "|";
    std::cout << std::endl;
    std::cout << "+";
    for (size_t j = 0; j < len - 1; j++)
        std::cout << "-";
    std::cout << "+" << std::endl;
    std::getline(std::cin, temp);
    if (std::cin.eof())
        this->ExitPhone();
    std::system("clear");
    }
    return ;
}