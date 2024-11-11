/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:32:06 by akastler          #+#    #+#             */
/*   Updated: 2023/10/17 17:34:54 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data() {
    std::cout << "Data default constructor set s1 to \"Hello\" and s2 to \"World\"" << std::endl;
    s1 = "Hello";
    s2 = "World";
}

Data::~Data() {
}

std::string Data::getString(int i) const {
    if (i == 1)
        return this->s1;
    else if (i == 2)
        return this->s2;
    std::cout << "Error: invalid index" << std::endl;
    return "";
}

void        Data::setString(std::string s, int i) {
    if (i == 1)
        this->s1 = s;
    else if (i == 2)
        this->s2 = s;
    else
        std::cout << "Error: invalid index" << std::endl;
}

Data::Data(Data const & src) {
    *this = src;
}

Data &      Data::operator=(Data const & rhs) {
    if (this != &rhs) {
        this->s1 = rhs.s1;
        this->s2 = rhs.s2;
    }
    return *this;
}