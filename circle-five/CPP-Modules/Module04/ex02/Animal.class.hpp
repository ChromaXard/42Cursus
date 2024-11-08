/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 10:09:03 by akastler          #+#    #+#             */
/*   Updated: 2023/10/10 18:19:09 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

#include <iostream>

class Animal
{
	protected:
		std::string		type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(Animal const &src);

		virtual ~Animal(void) = 0;

		Animal			&operator=(Animal const &rhs);
		
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif