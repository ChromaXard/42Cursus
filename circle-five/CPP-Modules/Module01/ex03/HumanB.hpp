/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:23:01 by akastler          #+#    #+#             */
/*   Updated: 2023/09/15 09:20:29 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class   HumanB
{
	public:
		HumanB(std::string name);
		~HumanB(void);
		void    attack(void);
		void    setWeapon(Weapon &weapon);
	private:
		std::string _name;
		Weapon      *_weapon;
};

#endif