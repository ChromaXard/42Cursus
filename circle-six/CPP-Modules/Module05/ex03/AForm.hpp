/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:45:08 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 15:52:44 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   _name;
        bool                _signed;
        int const           _gradeToSign;
        int const           _gradeToExec;

    protected:
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

        class NotSignedException : public::std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Form is not signed");
                }
        };
    
    public:
        AForm();
        AForm(std::string name, int grade_to_sign, int grade_to_exec);
        AForm(AForm const &src);
        virtual ~AForm();

        AForm &operator=(AForm const &rhs);

        std::string const   getName() const;
        bool                getSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExec() const;

        void                beSigned(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif