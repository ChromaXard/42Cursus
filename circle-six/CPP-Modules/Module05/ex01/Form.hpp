/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:45:08 by akastler          #+#    #+#             */
/*   Updated: 2023/10/05 11:02:18 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExec;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too high");
                }
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Grade is too low");
                }
        };
    
    public:
        Form();
        Form(std::string name, int grade_to_sign, int grade_to_exec);
        Form(Form const &src);
        ~Form();

        Form &operator=(Form const &rhs);

        std::string const   getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;

        void                beSigned(Bureaucrat &bureaucrat);      
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif