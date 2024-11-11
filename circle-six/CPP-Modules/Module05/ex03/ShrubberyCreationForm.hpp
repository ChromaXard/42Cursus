/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:27:59 by akastler          #+#    #+#             */
/*   Updated: 2023/10/06 15:24:14 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm( std::string const & target );
        ShrubberyCreationForm( ShrubberyCreationForm const & src );
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &    operator=( ShrubberyCreationForm const & rhs );

        void                        execute( Bureaucrat const & executor ) const;
        std::string                 getTarget( void ) const;
    
    private:
        const std::string                _target;
};

#endif