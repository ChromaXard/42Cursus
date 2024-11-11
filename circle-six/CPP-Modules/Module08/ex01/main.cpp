/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:43:20 by akastler          #+#    #+#             */
/*   Updated: 2023/11/16 11:25:01 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <list>

int main(void) {
    try{
        srand(time(NULL));
        Span sp = Span(20);
    
        sp.addNumber(3);
        sp.addNumber(6);
        
        std::vector<int> vec;
        for (int i = 0; i < 10; i++)
            vec.push_back(rand() % 100);
        sp.addNumbers(vec.begin(), vec.end());
        
        sp.addNumbers(5);
        
        std::list<int> test;
        
        test.push_back(5);
        
        sp.addNumbers(test.begin(), test.end());

        sp.showInformations();
    
        std::cout << "Shortest Span: "<< sp.shortestSpan() << std::endl;
        std::cout << " Longest Span: " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}