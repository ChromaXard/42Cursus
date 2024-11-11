/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:40 by akastler          #+#    #+#             */
/*   Updated: 2023/10/23 14:57:06 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) {
	*this = src;
	return ;
}

Bureaucrat::~Bureaucrat(void) {
	return ;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs){
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return(*this);
}

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::incrementGrade(void) {
	if (this->_grade == 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else
		this->_grade--;
}

void Bureaucrat::decrementGrade(void) {
	if (this->_grade == 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	else
		this->_grade++;
}

void Bureaucrat::testGradeHigh(std::string printOrNot) {
	for (int i = 0; i < 150; i++) {
		if (printOrNot == "y")
			std::cout << *this << std::endl;
		this->incrementGrade();
	}
}

void Bureaucrat::testGradeLow(std::string printOrNot) {
	for (int i = 0; i < 150; i++) {
		if (printOrNot == "y")
			std::cout << *this << std::endl;
		this->decrementGrade();
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}