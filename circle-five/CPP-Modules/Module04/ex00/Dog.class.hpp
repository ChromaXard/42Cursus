/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:07:12 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 16:03:18 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include <iostream>
#include "Animal.class.hpp"

class Dog: public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);

		virtual ~Dog(void);

		Dog				&operator=(Dog const &rhs);

		void	makeSound(void) const;
};

#endif