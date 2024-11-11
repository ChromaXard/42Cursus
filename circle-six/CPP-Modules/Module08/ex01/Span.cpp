/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:33:03 by akastler          #+#    #+#             */
/*   Updated: 2023/11/16 11:37:57 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>

Span::Span(void) : _sizeMax(0) {
    return ;
}

Span::Span(unsigned int n) : _sizeMax(n) {
    return ;
}

Span::Span(Span const & src) {
    *this = src;
    return ;
}

Span::~Span(void) {
    return ;
}

Span & Span::operator=(Span const & rhs){
    if (this != &rhs) {
        _vec = rhs._vec;
        _sizeMax = rhs._sizeMax;
    }
    return *this;
}

void Span::addNumber(int n) {
    if (_vec.size() < _sizeMax)
        _vec.push_back(n);
    else
        throw std::exception();
}

int Span::shortestSpan(void){
    if (_vec.size() <= 1)
        throw Span::TooFewNumbersException();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 1; i < tmp.size(); i++) {
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    }
    return min;
}

int Span::longestSpan(void){
    if (_vec.size() <= 1)
        throw Span::TooFewNumbersException();
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    return tmp[tmp.size() - 1] - tmp[0];
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) < 0)
        throw Span::NegativeNumberException();
    if (std::distance(begin, end) == 0)
        return ;
    if (_vec.size() + std::distance(begin, end) > _sizeMax)
        throw Span::TooManyNumbersException();
    _vec.insert(_vec.end(), begin, end);
}

void Span::addNumbers(std::list<int>::iterator begin, std::list<int>::iterator end) {
    if (std::distance(begin, end) < 0)
        throw Span::NegativeNumberException();
    if (std::distance(begin, end) == 0)
        return ;
    if (_vec.size() + std::distance(begin, end) > _sizeMax)
        throw Span::TooManyNumbersException();
    _vec.insert(_vec.end(), begin, end);
}

void Span::addNumbers(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
    if (std::distance(begin, end) < 0)
        throw Span::NegativeNumberException();
    if (std::distance(begin, end) == 0)
        return ;
    if (_vec.size() + std::distance(begin, end) > _sizeMax)
        throw Span::TooManyNumbersException();
    _vec.insert(_vec.end(), begin, end);
}

void Span::addNumbers(unsigned int numberOfRandomNumber) {
    srand(time(NULL));
    if (numberOfRandomNumber < 0)
        throw Span::NegativeNumberException();
    if (_vec.size() + numberOfRandomNumber > _sizeMax)
        throw Span::TooManyNumbersException();
    for (unsigned int i = 0; i < numberOfRandomNumber; i++)
        _vec.push_back(rand() % 1000);
}

void Span::addNumbers(std::vector<int> values) {
    if (std::distance(values.begin(), values.end()) == 0)
        return ;
    if (std::distance(values.begin(), values.end()) < 0)
        throw Span::NegativeNumberException();
    if (std::distance(values.begin(), values.end()) + _vec.size() > _sizeMax)
        throw Span::TooManyNumbersException();
    _vec.insert(_vec.end(), values.begin(), values.end());
}

void Span::addNumbers(const int *values, int SizeOfTab) {
    if (SizeOfTab < 0)
        throw Span::NegativeNumberException();
    if (SizeOfTab == 0)
        return ;
    if (SizeOfTab + _vec.size() > _sizeMax)
        throw Span::TooManyNumbersException();
    for (int i = 0; i < SizeOfTab; i++)
        _vec.push_back(values[i]);
}

void Span::showInformations(void) {
    std::cout << "     Size max: " << _sizeMax << std::endl;
    std::cout << "         Size: " << _vec.size() << std::endl;
    std::cout << "       Vector: ";
    for (unsigned int i = 0; i < _vec.size(); i++)
        std::cout << _vec[i] << " ";
    std::cout << std::endl;
    std::vector<int> tmp = _vec;
    std::sort(tmp.begin(), tmp.end());
    std::cout << "Sorted Vector: ";
    for (unsigned int i = 0; i < tmp.size(); i++)
        std::cout << tmp[i] << " ";
    std::cout << std::endl;
}