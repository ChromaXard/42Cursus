/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:48 by akastler          #+#    #+#             */
/*   Updated: 2023/11/28 15:19:06 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "PmergeMe: Error: invalid number of args" << std::endl;
        return (1);
    }
    try {
        PmergeMe p;
        for (int i = 1; i < argc; i++) {
            p.check(argv[i]);
            p.add(std::atoi(argv[i]));
        }
        p.launchProcess();
    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}