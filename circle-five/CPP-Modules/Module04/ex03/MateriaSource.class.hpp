/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.class.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 10:27:46 by akastler          #+#    #+#             */
/*   Updated: 2023/09/29 17:09:03 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP

#include "IMateriaSource.class.hpp"
#include <list>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_inventory[4];
		void			_deleteInventory();
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource();
		MateriaSource &	operator=(MateriaSource const & src);
		void			learnMateria(AMateria* materia);
		AMateria*		createMateria(std::string const & type);
};

#endif