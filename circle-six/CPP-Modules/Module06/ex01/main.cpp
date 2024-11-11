/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:35:05 by akastler          #+#    #+#             */
/*   Updated: 2023/10/31 13:33:22 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Data        d;
    uintptr_t   raw;
    Data*       ptr;

    raw = Serializer::serialize(&d);
    std::cout << "raw = " << raw << std::endl;
    std::cout << "d address = " << &d << std::endl;
    std::cout << "d.getString(1) = " << d.getString(1) << std::endl;
    std::cout << "d.getString(2) = " << d.getString(2) << std::endl;
    ptr = Serializer::deserialize(raw);
    std::cout << "ptr->getString(1) = " << ptr->getString(1) << std::endl;
    std::cout << "ptr->getString(2) = " << ptr->getString(2) << std::endl;
    ptr->setString("Bonjour", 1);
    ptr->setString("Monde", 2);
    std::cout << "ptr->getString(1) = " << ptr->getString(1) << std::endl;
    std::cout << "ptr->getString(2) = " << ptr->getString(2) << std::endl;
    std::cout << "d.getString(1) = " << d.getString(1) << std::endl;
    std::cout << "d.getString(2) = " << d.getString(2) << std::endl;
    return 0;
}