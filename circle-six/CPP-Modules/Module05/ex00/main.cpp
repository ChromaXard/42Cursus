/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:26 by akastler          #+#    #+#             */
/*   Updated: 2023/10/23 14:56:23 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <cstdlib>
#include <cctype>

int main(void) {
	std::system("clear");
	std::cout << "Welcome to the Bureaucrat creator!" << std::endl;
	std::cout << "You will be asked to enter the name and grade of the bureaucrat." << std::endl;
	std::cout << "The grade must be between 1 and 150. (if the grade is not between 1 and 150 default value will be chosen.)" << std::endl;
	std::cout << "The name must not be empty. (if the name is empty default value will be chosen.)" << std::endl;

	std::cout << "Choose the name of the bureaucrat: ";
	std::string name;
	std::getline(std::cin, name);
	if (name.empty() == 1 || name.length() == 0)
		name = "default";
	
	std::cout << "the name of the bureaucrat is: " << name << std::endl << "Choose the grade of the bureaucrat: ";
	std::string grade;
	std::getline(std::cin, grade);
	if (grade.empty() == 1 || grade.length() == 0)
		grade = "150";
	int grade_int = std::atoi(grade.c_str());
	std::cout << "the grade of the bureaucrat is: " << grade_int << std::endl;

	try {
		std::cout << std::endl << "creating bureaucrat with name and grade..." << std::endl;
		Bureaucrat b1(name, grade_int);
		std::cout << "bureaucrat created!" << std::endl;
		std::cout << b1 << std::endl;

		std::cout << "processing tests..." << std::endl << std::endl;

		std::string printOrNot;
		std::cout << "Do you want to print the tests? (y/n): ";
		std::getline(std::cin, printOrNot);
		if (printOrNot.empty() || printOrNot.length() == 0 || std::cin.eof())
			printOrNot = "n";
	
		std::cout << std::endl << "test of getName and getGrade..." << std::endl;
		std::cout << "name: " << b1.getName() << std::endl;
		std::cout << "grade: " << b1.getGrade() << std::endl;

		std::cout << std::endl << "test of incrementGrade and decrementGrade..." << std::endl;

		if (grade_int <= 150 / 2)
		{
			std::cout << std::endl << "incrementing grade to max..." << std::endl;
			b1.testGradeHigh(printOrNot);
		}
		else
		{
			std::cout << std::endl << "decrementing grade to min..." << std::endl;
			b1.testGradeLow(printOrNot);
		}
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}

// int main(void)
// {
// 	std::cout << "Test 1: Create a Bureaucrat with no arguments" << std::endl;
// 	try {
// 		Bureaucrat b1;
// 		std::cout << b1 << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "Test 2: Create a Bureaucrat with name and grade" << std::endl;
// 	try {
// 		Bureaucrat b2("B2", 2);
// 		std::cout << b2 << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "Test 3: Create a Bureaucrat with name and invalid grade" << std::endl;
// 	try {
// 		Bureaucrat b3("B3", 151);
// 		std::cout << b3 << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "Test 4: Create a Bureaucrat with name and grade and increment/decrement grade" << std::endl;
// 	try{
// 		Bureaucrat b4("B4", 2);
// 		std::cout << b4 << std::endl;
// 		b4.incrementGrade();
// 		std::cout << b4 << std::endl;
// 		b4.decrementGrade();
// 		std::cout << b4 << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "Test 5: Create a Bureaucrat with name and grade and increment grade too high" << std::endl;
// 	try{
// 		Bureaucrat b5("B5", 1);
// 		std::cout << b5 << std::endl;
// 		b5.incrementGrade();
// 		std::cout << b5 << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	std::cout << std::endl << "Test 6: Create a Bureaucrat with name and grade and decrement grade too low" << std::endl;
// 	try{
// 		Bureaucrat b6("B6", 150);
// 		std::cout << b6 << std::endl;
// 		b6.decrementGrade();
// 		std::cout << b6 << std::endl;
// 	}
// 	catch (std::exception & e) {
// 		std::cout << e.what() << std::endl;
// 	}

// }