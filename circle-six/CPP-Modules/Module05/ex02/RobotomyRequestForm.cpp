/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:26:53 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 14:35:31 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default") {
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src.getTarget(), 72, 45), _target(src.getTarget()) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target): AForm(target + "_RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &    RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
    (void)rhs;
    return *this;
}

void                        RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
    static int i = 0;
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else{
        if (i == 0) {
            i = 1;
            std::cout << "Target named : " << this->_target << " has been robotomized successfully." << std::endl;
        }
        else {
            i = 0;
            std::cout << "Robotomize for the target named : " << this->_target << " failed" << std::endl;
        }
    }
}

std::string                 RobotomyRequestForm::getTarget( void ) const {
    return this->_target;
}