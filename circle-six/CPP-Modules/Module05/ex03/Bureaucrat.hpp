/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:08:46 by akastler          #+#    #+#             */
/*   Updated: 2023/10/23 15:09:58 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		std::string const	_name;
		int					_grade;
	
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
		Bureaucrat(void);
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat(void);

		Bureaucrat &		operator=(Bureaucrat const & rhs);

		std::string			getName(void) const;
		int					getGrade(void) const;
		void				incrementGrade(void);
		void				decrementGrade(void);

		void				testGradeHigh(std::string printOrNot);
		void				testGradeLow(std::string print);

		void				signForm(AForm & form);
		void				executeForm(AForm const & form) const;
};

std::ostream &				operator<<(std::ostream & o, Bureaucrat const & rhs);

#endif