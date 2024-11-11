/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:53:26 by axel              #+#    #+#             */
/*   Updated: 2023/11/03 11:27:47 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"
#include <cstdlib>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

std::string generateRandomWord(int length) {
    std::string alphanum = "abcdefghijklmnopqrstuvwxyz0123456789";
    const int alphabetSize = alphanum.length();

    std::string randomWord;
    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % alphabetSize - 1;
        randomWord += alphanum[randomIndex];
    }
    if (randomWord.length() == 0)
        randomWord = "empty";
    return randomWord;
}

int main( void ) {
    {
        std::cout << "----- main of the subject -----" << std::endl;
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "----- other tests -----" << std::endl;
        srand(time(NULL));
        int nbTest = rand() % 10 + 1;
        std::cout << RED;
        std::cout << "nbTest = " << nbTest << std::endl;
        std::cout << RESET;
        std::string s1 = generateRandomWord((rand() % 15) + 1);
        std::string s2 = generateRandomWord((rand() % 15) + 1);
        std::cout << YELLOW;
        std::cout << "--- Informations of s1 ---" << std::endl;
        std::cout << "s1 = " << s1 << std::endl;
        std::cout << "s1.length() = " << s1.length() << std::endl;
        std::cout << "s1 address = " << &s1 << std::endl;
        std::cout << std::endl;
        std::cout << "--- Informations of s2 ---" << std::endl;
        std::cout << "s2 = " << s2 << std::endl;
        std::cout << "s2.length() = " << s2.length() << std::endl;
        std::cout << "s2 address = " << &s2 << std::endl;
        std::cout << RESET;
        std::cout << std::endl;
        for (int i = 0; i < nbTest; i++) {
            std::cout << BLUE;
            std::cout << "--- choosing function... ---" << std::endl;
            int nb = rand() % 3;
            std::cout << "nb = " << nb << std::endl;
            std::cout << RESET;
            if (nb == 0) {
                std::cout << "swap" << std::endl;
                std::cout << "before swap: " << std::endl;
                std::cout << "s1 = " << s1 << std::endl;
                std::cout << "s2 = " << s2 << std::endl;
                ::swap(s1, s2);
                std::cout << "after swap: " << std::endl;
                std::cout << "s1 = " << s1 << std::endl;
                std::cout << "s2 = " << s2 << std::endl;
            }
            else if (nb == 1) {
                std::cout << "min of s1 and s2" << std::endl;
                std::cout << "s1 = " << s1 << std::endl;
                std::cout << "s2 = " << s2 << std::endl;
                std::cout << "min = " << ::min(s1, s2) << std::endl;
            }
            else {
                std::cout << "max of s1 and s2" << std::endl;
                std::cout << "s1 = " << s1 << std::endl;
                std::cout << "s2 = " << s2 << std::endl;
                std::cout << "max = " << ::max(s1, s2) << std::endl;
            }
        }

    }
}