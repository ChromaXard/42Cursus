/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:02:41 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 14:50:30 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) {
    *this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const & rhs) {
    (void)rhs;
    return *this;
}

static AForm *createShrubberyCreationForm(std::string target) {
    return new ShrubberyCreationForm(target);
}

static AForm *createRobotomyRequestForm(std::string target) {
    return new RobotomyRequestForm(target);
}

static AForm *createPresidentialPardonForm(std::string target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const &typeForm, std::string const &target) {
    std::string Forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *(*FormsCreate[3])(std::string) = {createShrubberyCreationForm, createRobotomyRequestForm, createPresidentialPardonForm};
    for (int i = 0; i < 3; i++) {
        if (typeForm == Forms[i]) {
            std::cout << "Intern creates " << typeForm << std::endl;
            return FormsCreate[i](target);
        }
    }
    std::cout << "Intern doesn't know this form" << std::endl;
    return NULL;
}