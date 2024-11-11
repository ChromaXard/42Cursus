/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:27:49 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 10:29:24 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default") {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src.getTarget(), 25, 5), _target(src.getTarget()) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target): AForm(target + "_PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &    PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {
    (void)rhs;
    return *this;
}

void                        PresidentialPardonForm::execute( Bureaucrat const & executor ) const {
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::string                 PresidentialPardonForm::getTarget( void ) const {
    return this->_target;
}