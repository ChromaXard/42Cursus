/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:30:13 by akastler          #+#    #+#             */
/*   Updated: 2023/11/27 14:46:04 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << YELLOW;
        std::cerr << "RPN: Error: bad usage ( ./RPN <string> )" << std::endl;
        std::cout << RESET;
    }
    else {
        try {
            RPN rpn;
            rpn.treatString(argv[1]);
        }
        catch (std::exception const &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << RESET;
    }
}