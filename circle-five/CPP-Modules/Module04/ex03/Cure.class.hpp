/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:14:59 by akastler          #+#    #+#             */
/*   Updated: 2023/09/23 10:57:37 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP

# include "AMateria.class.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(Cure const & src);
		~Cure();

		Cure &           operator=(Cure const & rhs);

		AMateria*       clone() const;
		virtual void    use(ICharacter& target);
};

#endif