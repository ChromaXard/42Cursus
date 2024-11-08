/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:46:58 by akastler          #+#    #+#             */
/*   Updated: 2023/09/23 08:39:40 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string _name;

	public:
		DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(DiamondTrap const &src);
		
        ~DiamondTrap();

		DiamondTrap	&operator=(DiamondTrap const &rhs);

		void		attack(std::string const &src);
		void		whoAmI(void);
};

#endif