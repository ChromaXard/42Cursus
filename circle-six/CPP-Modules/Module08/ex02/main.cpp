/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 15:07:20 by akastler          #+#    #+#             */
/*   Updated: 2023/11/16 11:19:24 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << "Top of mstack: " << mstack.top() << std::endl;

    std::cout << std::endl;
    mstack.pop();
    std::cout << "Size of mstack after a pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    {
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        std::cout << std::endl << "all values stocked in mstack" << std::endl;
        while (it != ite)
        {   
            std::cout << "Value : " << *it << std::endl;
            ++it;
        }
    }

    std::cout << std::endl << "creating a mutantStack<int> s(mstack)" << std::endl;
    MutantStack<int> s(mstack);
    std::cout << "Size of s: " << s.size() << std::endl;
    s.push(24000);
    std::cout << "Size of s after a push: " << s.size() << std::endl;

    std::cout << "adding numbers in s..." << std::endl;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        s.push(rand() % 10000);
    }
    std::cout << std::endl;
    {
        MutantStack<int>::iterator it = s.begin();
        MutantStack<int>::iterator ite = s.end();
        ++it;
        --it;
        std::cout << std::endl << "all values stocked in s" << std::endl;
        while (it != ite)
        {   
            std::cout << "Value : " << *it << std::endl;
            ++it;
        }
    }

    std::cout << std::endl;
    std::cout << "Size of mstack: " << mstack.size() << std::endl;
    
    std::cout << std::endl;
    MutantStack<int> s2;
    s2 = s;
    std::cout << "Size of s2 (s2 is a copy of s with the equal operator): " << s2.size() << std::endl;
    

    return 0;
}