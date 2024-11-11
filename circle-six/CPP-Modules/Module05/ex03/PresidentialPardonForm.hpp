/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:27:39 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 10:25:49 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm( std::string const & target );
        PresidentialPardonForm( PresidentialPardonForm const & src );
        ~PresidentialPardonForm();

        PresidentialPardonForm &    operator=( PresidentialPardonForm const & rhs );

        void                        execute( Bureaucrat const & executor ) const;
        std::string                 getTarget( void ) const;
    
    private:
        const std::string                _target;
};

#endif