/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:27:44 by akastler          #+#    #+#             */
/*   Updated: 2023/10/31 09:45:07 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( Serializer const & src ) {
    (void)src;
}

Serializer::Serializer() {
}

Serializer::~Serializer() {
}

Serializer &        Serializer::operator=( Serializer const & rhs ) {
    (void)rhs;
    return *this;
}

uintptr_t   Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}