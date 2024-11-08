/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:08:27 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 18:06:54 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

#include <iostream>
#include "Animal.class.hpp"
#include "Brain.class.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;
	public:
		Cat(void);
		Cat(Cat const &src);
		
		virtual ~Cat(void);

		Cat				&operator=(Cat const &rhs);

		void	makeSound(void) const;
};

#endif