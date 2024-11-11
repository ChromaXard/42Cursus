/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:37 by axel              #+#    #+#             */
/*   Updated: 2023/11/09 10:50:52 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "iter.hpp"

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

static void printHead(int length, std::string type) {
    std::cout << YELLOW;
    std::cout << "iter(tab, " << length << ", print<" << type << ">);" << std::endl;
    std::cout << "-> ";
    std::cout << RESET;
}

static void printBack() {
    std::cout << std::endl;
    std::cout << std::endl;
}

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

int main(void) {
    srand(time(NULL));
    {
        std::cout << BLUE;
        std::cout << "--- Test with int array ---" << std::endl;
        std::cout << RESET;
        int numberOfTest = rand() % 10;
        if (numberOfTest == 0)
            numberOfTest = 1;
        std::cout << RED;
        std::cout << "Number of test: " << numberOfTest << std::endl;
        std::cout << RESET;
        for (int i = 0; i < numberOfTest; i++){
            int lengthArrayInt = rand() % 20 + rand() % 10;
            if (lengthArrayInt == 0)
                lengthArrayInt = 1;
            int tab[lengthArrayInt];
            std::cout << CYAN;
            std::cout << "int tab[" << lengthArrayInt << "] = { ";
            for (int i = 0; i < lengthArrayInt; i++) {
                tab[i] = rand() % 1000;
                std::cout << tab[i];
                if (i < lengthArrayInt - 1)
                    std::cout << ", ";
            }
            std::cout << " };" << std::endl;
            std::cout << std::endl;
            std::cout << RESET;
            if (i % 2 == 0) {
                printHead(lengthArrayInt, "int");
                iter(tab, lengthArrayInt, print<int>);
            }
            else {
                int temp = rand() % lengthArrayInt + 1;
                if (temp > lengthArrayInt)
                    temp = lengthArrayInt;
                printHead(temp, "int");
                iter(tab, temp, print<int>);
            }
            printBack();
        }
    }
    {
        std::cout << BLUE;
        std::cout << "--- Test with string array ---" << std::endl;
        std::cout << RESET;
        int numberOfTest = rand() % 10;
        if (numberOfTest == 0)
            numberOfTest = 1;
        std::cout << RED;
        std::cout << "Number of test: " << numberOfTest << std::endl;
        std::cout << RESET;
        for (int i = 0; i < numberOfTest; i++){
            int lengthArrayString = rand() % 20 + rand() % 10;
            if (lengthArrayString == 0)
                lengthArrayString = 1;
            std::string tab[lengthArrayString];
            std::cout << CYAN;
            std::cout << "std::string tab[" << lengthArrayString << "] = { ";
            for (int i = 0; i < lengthArrayString; i++) {
                tab[i] = generateRandomWord(rand() % 3 + rand() % 2);
                std::cout << "\"" << tab[i] << "\"";
                if (i < lengthArrayString - 1)
                    std::cout << ", ";
            }
            std::cout << " };" << std::endl;
            std::cout << std::endl;
            std::cout << RESET;
            if (i % 2 == 0) {
                printHead(lengthArrayString, "std::string");
                iter(tab, lengthArrayString, print<std::string>);
            }
            else {
                int temp = rand() % lengthArrayString + 1;
                if (temp > lengthArrayString)
                    temp = lengthArrayString;
                printHead(temp, "std::string");
                iter(tab, temp, print<std::string>);
            }
            printBack();
        }
    }
    {
        std::cout << BLUE;
        std::cout << "--- Error tests ---" << std::endl;
        std::cout << RESET;
        std::string tab[1];
        tab[0] = "test";

        std::cout << CYAN;
        std::cout << "std::string tab[1] = { \"test\" };" << std::endl;
        std::cout << std::endl;
        std::cout << RESET;
        std::cout << YELLOW;
        
        printHead(-1, "std::string");
        iter(tab, -1, print<std::string>);
        printBack();
        
        printHead(0, "std::string");
        iter(tab, 0, print<std::string>);
        printBack();

    }
    return 0;
}