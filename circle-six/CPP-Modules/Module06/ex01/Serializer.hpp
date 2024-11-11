/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:25:17 by akastler          #+#    #+#             */
/*   Updated: 2023/10/30 12:20:18 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include "Data.hpp"

class Serializer
{
    private:
        Serializer( Serializer const & src );
        Serializer();
        ~Serializer();
        Serializer &        operator=( Serializer const & rhs );
    public:
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
};

#endif