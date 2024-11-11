/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:13:38 by akastler          #+#    #+#             */
/*   Updated: 2023/10/30 09:28:05 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConvertor.hpp"
#include <limits>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "convert: Error: no arguments" << std::endl;
        return (1);
    }
    else if (argc > 2) {
        std::cout << "convert: Error: too much arguments" << std::endl;
        return (1);
    }
    ScalarConvertor::convert(argv[1]);
    return (0);
}