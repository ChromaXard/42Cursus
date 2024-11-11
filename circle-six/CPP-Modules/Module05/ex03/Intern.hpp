/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 13:59:45 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 14:50:07 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(Intern const & src);
        ~Intern();

        Intern &        operator=(Intern const & rhs);

        AForm *         makeForm(std::string const & formName, std::string const & target);
};

#endif