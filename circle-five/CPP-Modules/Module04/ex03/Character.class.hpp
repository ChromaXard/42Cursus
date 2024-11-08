/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 09:42:30 by akastler          #+#    #+#             */
/*   Updated: 2023/09/23 12:27:33 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP

# include "ICharacter.class.hpp"
# include "AMateria.class.hpp"
# include <list>

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria		*_inventory[4];
		void			_deleteInventory();

	public:
		Character();
		Character(std::string name);
		Character(Character const & src);
		~Character();

		Character &           operator=(Character const & rhs);

		std::string const &   getName() const;
		void                  equip(AMateria* m);
		void                  unequip(int idx);
		void                  use(int idx, ICharacter& target);
};

#endif