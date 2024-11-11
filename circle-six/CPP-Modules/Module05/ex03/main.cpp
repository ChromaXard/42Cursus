/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:26 by akastler          #+#    #+#             */
/*   Updated: 2023/10/23 15:18:41 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <cctype>

static void printStart() {
	std::system("clear");
	std::cout << "Welcome to ex03 - Bureaucrat (part 4)" << std::endl;
	std::cout << "In this exercise we implement the Intern class, this class exist only for create forms (shrubbery creation, robotomy request, presidential pardon)." << std::endl << std::endl;
}

static void FormCreationSignExec(Bureaucrat &b1) {
	std::cout << "it's time to create and sign a form" << std::endl;
	std::cout << "Enter a target for the form: ";
	std::string formName;
	std::getline(std::cin, formName);
	if (formName.empty())
		formName = "default";
	std::cout << "enter the name of the form type you want : ";
	std::string formType;
	std::getline(std::cin, formType);
	if (formType.empty())
		formType = "default";
	AForm *f1;
	Intern someRandomIntern;
	f1 = someRandomIntern.makeForm(formType, formName);
	if (f1)
	{
		std::cout << "informations of the form :" << std::endl << *f1 << std::endl << std::endl;
		std::cout << "it's time to sign and execute the form" << std::endl;
		b1.signForm(*f1);
		b1.executeForm(*f1);
		delete f1;
	}
}

int main(void) {
	printStart();
	std::cout << "Enter a name for the bureaucrat: ";
	std::string name;
	std::getline(std::cin, name);
	if (name.empty())
		name = "default";
	std::cout << "Enter a grade for the bureaucrat: ";
	std::string grade;
	std::getline(std::cin, grade);
	if (grade.empty())
		grade = "150";
	try {
		Bureaucrat b1(name, std::atoi(grade.c_str()));
		std::cout << b1 << std::endl << std::endl;
		FormCreationSignExec(b1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
