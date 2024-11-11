/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:26 by akastler          #+#    #+#             */
/*   Updated: 2023/10/23 14:54:21 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <cctype>

int main(void) {
	std::system("clear");
	std::cout << "Welcome to ex01 - Bureaucrat (part 2)" << std::endl << std::endl;
	std::cout << "In this exercise we implement the new class named form. It's a class takes 3 arguments to create : the name for the form, the grade needed for sign and the grade for execution" << std::endl << std::endl;
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

		std::cout << "it's time to create and sign a form" << std::endl;
		std::cout << "Enter a name for the form: ";
		std::string formName;
		std::getline(std::cin, formName);
		if (formName.empty())
			formName = "default";
		
		std::cout << "Enter a grade to sign the form: ";
		std::string gradeToSign;
		std::getline(std::cin, gradeToSign);
		if (gradeToSign.empty())
			gradeToSign = "150";
		
		std::cout << "Enter a grade to execute the form: ";
		std::string gradeToExec;
		std::getline(std::cin, gradeToExec);
		if (gradeToExec.empty())
			gradeToExec = "150";
		Form f1(formName, std::atoi(gradeToSign.c_str()), std::atoi(gradeToExec.c_str()));
		
		std::cout << f1 << std::endl << std::endl;
		std::cout << "it's time to sign the form" << std::endl;
		b1.signForm(f1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}