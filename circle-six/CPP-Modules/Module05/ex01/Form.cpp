/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:45:02 by akastler          #+#    #+#             */
/*   Updated: 2023/10/05 11:12:07 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {
    return ;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_exec) : _name(name), _signed(false), _gradeToSign(grade_to_sign), _gradeToExec(grade_to_exec) {
    if (grade_to_sign < 1 || grade_to_exec < 1)
        throw Form::GradeTooHighException();
    else if (grade_to_sign > 150 || grade_to_exec > 150)
        throw Form::GradeTooLowException();
    return ;
}

Form::Form(Form const &src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExec(src.getGradeToExec()) {
    *this = src;
    return ;
}

Form::~Form() {
    return ;
}

Form &Form::operator=(Form const &rhs) {
    if (this != &rhs)
        this->_signed = rhs.getSigned();
    return *this;
}

std::string const   Form::getName() const {
    return this->_name;
}

bool    Form::getSigned() const {
    return this->_signed;
}

int Form::getGradeToSign() const {
    return this->_gradeToSign;
}

int Form::getGradeToExec() const {
    return this->_gradeToExec;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() <= this->_gradeToSign)
        this->_signed = true;
    else
        throw Form::GradeTooLowException();
    return ;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
    o << "Form " << rhs.getName() << " is ";
    if (rhs.getSigned())
        o << "signed";
    else
        o << "not signed";
    o << " and requires grade " << rhs.getGradeToSign() << " to sign and grade " << rhs.getGradeToExec() << " to execute." << std::endl;
    return o;
}
