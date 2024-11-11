/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:38:45 by akastler          #+#    #+#             */
/*   Updated: 2023/12/04 15:29:10 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

#define RESET "\033[0m"
#define YELLOW "\033[33m"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << YELLOW;
        std::cerr << "Usage: ./btc [file]" << std::endl;
        std::cout << RESET;
        return (1);
    }
    try {
        BitcoinExchange test;
        test.setData("data.csv");
        test.readInput(argv[1]);
        std::cout << RESET;
        return (0);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
}