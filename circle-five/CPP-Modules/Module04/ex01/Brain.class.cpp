/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:23:07 by akastler          #+#    #+#             */
/*   Updated: 2023/09/18 10:24:51 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.class.hpp"

Brain::Brain() {
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(Brain const & src) {
	std::cout << "Copy Brain constructor called" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Default Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const & rhs) {
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = rhs._ideas[i];
	}
	return (*this);
}