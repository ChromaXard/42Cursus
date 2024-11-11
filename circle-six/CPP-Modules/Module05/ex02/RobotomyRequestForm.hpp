/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:27:04 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 14:30:27 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
    public:
        RobotomyRequestForm();
        RobotomyRequestForm( std::string const & target );
        RobotomyRequestForm( RobotomyRequestForm const & src );
        ~RobotomyRequestForm();

        RobotomyRequestForm &    operator=( RobotomyRequestForm const & rhs );

        void                        execute( Bureaucrat const & executor ) const;
        std::string                 getTarget( void ) const;
    
    private:
        const std::string                _target;
};

#endif