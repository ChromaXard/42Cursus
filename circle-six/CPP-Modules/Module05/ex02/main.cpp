/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:26 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 14:47:51 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <cctype>

static void printStart() {
	std::system("clear");
	std::cout << "Welcome to ex02 - Bureaucrat (part 3)" << std::endl;
	std::cout << "this exercise include creating 3 types of Form (ShrubberyCreationForm, RobotomyRequestForm and PresidentialPardonForm) and it's now impossible to create classic Form." << std::endl << std::endl;
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
	AForm *f1 = NULL;
	std::string Forms[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *f2[4] = {new ShrubberyCreationForm(formName), new RobotomyRequestForm(formName), new PresidentialPardonForm(formName), NULL};
	int i = 0;
	while (i < 3 && formType != Forms[i]){
		delete f2[i];
		i++;
	}
	if (f2[i] == NULL) {
		std::cout << "this form doesn't exist" << std::endl;
		return ;
	}
	f1 = f2[i++];
	while (i < 3) {
		delete f2[i];
		i++;
	}
	std::cout << "informations of the form :" << std::endl << *f1 << std::endl << std::endl;
	std::cout << "it's time to sign and execute the form" << std::endl;
	b1.signForm(*f1);
	b1.executeForm(*f1);
	delete f1;
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
