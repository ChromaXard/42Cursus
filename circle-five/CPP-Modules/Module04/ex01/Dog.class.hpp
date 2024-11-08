/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:07:12 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 18:13:25 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

#include <iostream>
#include "Animal.class.hpp"
#include "Brain.class.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	public:
		Dog(void);
		Dog(Dog const &src);

		virtual ~Dog(void);

		Dog				&operator=(Dog const &rhs);

		void	makeSound(void) const;
};

#endif