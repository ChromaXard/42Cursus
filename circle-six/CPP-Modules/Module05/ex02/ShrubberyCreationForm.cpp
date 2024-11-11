/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:26:02 by akastler          #+#    #+#             */
/*   Updated: 2023/10/20 16:49:05 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src.getTarget(), 145, 137), _target(src.getTarget()) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target): AForm(target + "_ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &    ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {
    (void)rhs;
    return *this;
}

void                        ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
    if (this->getSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();
    else{
        std::string filename = getTarget() + "_shrubbery";
        std::ofstream   file(filename.c_str());
        for (int i = 0; i < 4; i++)
        {
            file << "       _-_               _-_               _-_               _-_       " << std::endl;
            file << "    /~~   ~~\\         /~~   ~~\\         /~~   ~~\\         /~~   ~~\\    " << std::endl;
            file << " /~~         ~~\\   /~~         ~~\\   /~~         ~~\\   /~~         ~~\\ " << std::endl;
            file << "{               } {               } {               } {               }" << std::endl;
            file << " \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  /   \\  _-     -_  / " << std::endl;
            file << "   ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~       ~  \\\\ //  ~   " << std::endl;
            file << "_- -   | | _- _   _- -   | | _- _   _- -   | | _- _   _- -   | | _- _  " << std::endl;
            file << "  _ -  | |   -_     _ -  | |   -_     _ -  | |   -_     _ -  | |   -_  " << std::endl;
            file << "      // \\\\             // \\\\             // \\\\             // \\\\      " << std::endl;
            file << std::endl;
        }
    }
}

std::string                 ShrubberyCreationForm::getTarget( void ) const {
    return this->_target;
}