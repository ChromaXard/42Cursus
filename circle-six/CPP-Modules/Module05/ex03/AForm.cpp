/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:45:02 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 10:16:43 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
    return ;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _gradeToSign(grade_to_sign), _gradeToExec(grade_to_exec) {
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw AForm::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw AForm::GradeTooLowException();
    return ;
}

AForm::AForm(AForm const &src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {
    *this = src;
    return ;
}

AForm::~AForm() {
    return ;
}

AForm &AForm::operator=(AForm const &rhs) {
    if (this != &rhs)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string const   AForm::getName() const {
    return this->_name;
}

bool    AForm::getSigned() const {
    return this->_signed;
}

int AForm::getGradeToSign() const {
    return this->_gradeToSign;
}

int AForm::getGradeToExec() const {
    return this->_gradeToExec;
}

void AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw AForm::GradeTooLowException();
    return ;
}

void AForm::execute(Bureaucrat const &executor) const {
    if (this->_signed == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->_gradeToExec)
        throw AForm::GradeTooLowException();
    return ;
}

std::ostream &operator<<(std::ostream &o, AForm const &rhs) {
    o << "AForm " << rhs.getName() << " is ";
    if (rhs.getSigned())
        o << "signed";
    else
        o << "not signed";
    o << " and requires grade " << rhs.getGradeToSign() << " to sign and grade " << rhs.getGradeToExec() << " to execute." << std::endl;
    return o;
}
