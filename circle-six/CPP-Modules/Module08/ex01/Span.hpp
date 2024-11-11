/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:35:26 by akastler          #+#    #+#             */
/*   Updated: 2023/11/16 11:37:09 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include <exception>

class Span {
    public:
        Span(void);
        Span(unsigned int n);
        Span(Span const & src);
        ~Span(void);

        Span & operator=(Span const & rhs);

        void addNumber(int n);

        int shortestSpan(void);
        int longestSpan(void);

        void addNumbers(unsigned int numberOfRandomNumber);
        void addNumbers(std::vector<int> values);
        void addNumbers(const int *values, int SizeOfTab);

        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end);
        void addNumbers(std::deque<int>::iterator begin, std::deque<int>::iterator end);
        void showInformations(void);

    private:
        std::vector<int> _vec;
        unsigned int _sizeMax;

        class TooFewNumbersException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "Too few numbers";
                }
        };

        class TooManyNumbersException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "Too many numbers";
                }
        };

        class NegativeNumberException : public std::exception {
            public:
                virtual const char * what() const throw() {
                    return "Negative number";
                }
        };
};