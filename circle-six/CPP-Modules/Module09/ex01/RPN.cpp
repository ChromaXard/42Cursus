/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:30:19 by akastler          #+#    #+#             */
/*   Updated: 2023/12/04 16:39:30 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>

#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

RPN::RPN(void) {
}

RPN::RPN(RPN const &src) {
    *this = src;
}

RPN &RPN::operator=(RPN const &src) {
    if (this != &src) {
        this->_numbers = src._numbers;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::applyOperator(std::string const &oper) {
    long long int nbrs[2];
    long long int result;
    if (_numbers.size() < 2)
        throw std::logic_error("RPN: Invalid expression (too few numbers)");
    nbrs[0] = _numbers.top();
    _numbers.pop();
    nbrs[1] = _numbers.top();
    _numbers.pop();
    if (oper == "+") {
        result = nbrs[1] + nbrs[0];
    }
    else if (oper == "-") {
        result = nbrs[1] - nbrs[0];
    }
    else if (oper == "*") {
        result = nbrs[1] * nbrs[0];
    }
    else if (oper == "/") {
        if (nbrs[0] == 0)
            throw std::logic_error("RPN: Invalid expression (division by 0)");
        result = nbrs[1] / nbrs[0];
    }
    else
        throw std::logic_error("RPN: Invalid expression");
    _numbers.push(result);
}

void RPN::checkErrors(std::string const &src) {
    int flag = 0;
    int nbrOfSigns = 0;
    int nbrOfNbrs = 0;
    for (unsigned int i = 0; i < src.length(); i++) {
        if (src[i] == ' ') {
            if (flag == 0)
                throw std::logic_error("RPN: Invalid expression space");
            flag = 0;
            while (src[i] == ' ')
                i++;
            i--;
        }
        else {
            if (src[i] != '-' && src[i] != '+' && src[i] != '/' && src[i] != '*') {
                if (flag == 1)
                    throw std::logic_error("RPN: Invalid expression number");
                else if (src[i] < '0' || src[i] > '9')
                    throw std::logic_error("RPN: Invalid expression number");
                else{
                    nbrOfNbrs++;
                    flag = 1;
                }
            }
            else {
                if (flag == 1)
                    throw std::logic_error("RPN: Invalid expression sign");
                else if (src[i] != '-' && src[i] != '+' && src[i] != '/' && src[i] != '*')
                    throw std::logic_error("RPN: Invalid expression sign");
                else {
                    nbrOfSigns++;
                    flag = 1;
                }
            }
        }
    }
    if (nbrOfNbrs - nbrOfSigns != 1)
        throw std::logic_error("RPN: Invalid expression (wrong number of numbers)");
}

void RPN::treatString(std::string const &src) {
    int flag = 0;
    std::cout << RED;
    checkErrors(src);
    {
        for (unsigned int i = 0; i < src.length(); i++) {
            if (src[i] == ' ') {
                if (flag == 0)
                    throw std::logic_error("RPN: Invalid expression");
                flag = 0;
                while (src[i] == ' ')
                    i++;
                i--;
            }
            else if (src[i] >= '0' && src[i] <= '9') {
                if (flag == 1)
                    throw std::logic_error("RPN: Invalid expression");
                _numbers.push(std::atoi(src.substr(i).c_str()));
                flag = 1;
            }
            else if (src[i] == '+' || src[i] == '-' || src[i] == '/' || src[i] == '*') {
                if (flag == 1)
                    throw std::logic_error("RPN: Invalid expression sign");
                applyOperator(src.substr(i, 1));
                flag = 1;
            }
        }
        if (_numbers.size() != 1)
            throw std::logic_error("RPN: Invalid expression");
        else {
            std::cout << GREEN;
            // std::cout << "The result of expression \"" << src << "\" with RPN method equals:" << std::endl;
            std::cout << _numbers.top() << std::endl;
            _numbers.pop();
        }
    }
}