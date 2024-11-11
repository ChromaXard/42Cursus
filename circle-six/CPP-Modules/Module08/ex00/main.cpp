/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 08:41:34 by akastler          #+#    #+#             */
/*   Updated: 2023/11/16 10:41:01 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <cstdlib>
#include <iostream>
#include <iomanip>

int main(void) {
    std::list<int> list;

    int maxNumber = 100;
    srand(time(NULL));
    for (int i = 0; i < maxNumber; i++)
        list.push_back(rand() % maxNumber);
    {
        int range = 1;
        for (std::list<int>::iterator it = list.begin(); it != list.end(); it++){
             if ((std::distance(list.begin(), it) + 1) % 10 == 1)
                std::cout << "range : " << range << " - " << range + 9 << std::endl;
            std::cout << std::setw(3) << *it;
            if ((std::distance(list.begin(), it) + 1) % 10 != 0 || std::distance(list.begin(), it) == 0)
                std::cout << ",";
            else {
                range += 10;
                std::cout << std::endl;
            }
        }
        std::cout << std::endl;
    }
    int find = rand() % maxNumber;
    std::cout << "easyfind(list, " << find << ")" << std::endl;
    int result = easyfind(list, find);
    if (result == -1)
        std::cout << "not found" << std::endl;
    else
        std::cout << "first occurence is : "<< result << std::endl;    
}