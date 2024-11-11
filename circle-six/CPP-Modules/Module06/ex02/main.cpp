/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:52:59 by akastler          #+#    #+#             */
/*   Updated: 2023/10/17 18:11:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>

Base*   generate(void) {
    srand(time(NULL));
    int random = rand() % 3;
    std::cout << "random = " << random << std::endl;

    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void identify(Base * object) {
    std::cout << "identify(Base * object)" << std::endl;
    if (dynamic_cast<A*>(object))
        std::cout << "The base is A" << std::endl;
    else if (dynamic_cast<B*>(object))
        std::cout << "The base is B" << std::endl;
    else if (dynamic_cast<C*>(object))
        std::cout << "The base is C" << std::endl;
    else
        std::cout << "The base is unknown" << std::endl;
}

void identify(Base & object) {
    std::cout << "identify(Base & object)" << std::endl;
    try {
        A & a = dynamic_cast<A&>(object);
        std::cout << "The base is A" << std::endl;
        (void)a;
    }
    catch (std::exception &bc) {
        try {
            B & b = dynamic_cast<B&>(object);
            std::cout << "The base is B" << std::endl;
            (void)b;
        }
        catch (std::exception &bc) {
            try {
                C & c = dynamic_cast<C&>(object);
                std::cout << "The base is C" << std::endl;
                (void)c;
            }
            catch (std::exception &bc) {
                std::cout << "The base is unknown" << std::endl;
            }
        }
    }
}

int main(void) {
    Base * base = generate();
    identify(base);
    identify(*base);
    delete base;
}