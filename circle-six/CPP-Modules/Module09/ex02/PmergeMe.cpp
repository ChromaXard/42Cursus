/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:42 by akastler          #+#    #+#             */
/*   Updated: 2023/11/28 15:31:28 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <algorithm>
#include <ctime>

PmergeMe::PmergeMe(void) {
    return ;
}

PmergeMe::PmergeMe(PmergeMe const & src) {
    *this = src;
    return ;
}

PmergeMe::~PmergeMe(void) {
    return ;
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
    if (this != &rhs) {
        this->_deque = rhs._deque;
        this->_vector = rhs._vector;
    }
    return *this;
}

void PmergeMe::add(int n) {
    if (n < 0) {
        throw std::out_of_range("PmergeMe: Error: out of range");
    }
    this->_origin.push_back(n);
    return ;
}

void PmergeMe::check(std::string str) {
    if (str.length() == 1 && !isdigit(str[0])) {
        throw std::logic_error("PmergeMe: Error: invalid argument");
    }
    else if (str.length() > 1) {
        for (size_t i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                throw std::logic_error("PmergeMe: Error: invalid argument");
            }
        }
    }
    long int n = std::atol(str.c_str());
    if (n > 2147483647 || n < 0) {
        throw std::out_of_range("PmergeMe: Error: out of range");
    }
    return ;
}

void PmergeMe::launchProcess() {
    double tempsVector = 0, tempsDeque = 0;

    {
        std::clock_t debut, fin;
        debut = std::clock();
        setNumberVector();
        fin = std::clock();
        tempsVector = static_cast<double>(fin - debut) / static_cast<double>(CLOCKS_PER_SEC);
    }
    {
        std::clock_t debut, fin;
        debut = std::clock();
        setNumberDeque();
        fin = std::clock();
        tempsDeque = static_cast<double>(fin - debut) / static_cast<double>(CLOCKS_PER_SEC);
    }
    printResultProcess(tempsVector, tempsDeque);
}

void PmergeMe::printResultProcess(double tempsVector, double tempsDeque) {
    std::cout << "Before: ";
    if (_origin.size() > 5) {
        for (unsigned int i = 0; i < 4; i++) {
            std::cout << _origin[i] << " ";
        }
        std::cout << "[...]" << std::endl;
    }
    else {
        for (unsigned int i = 0; i < _origin.size(); i++) {
            std::cout << _origin[i];
            if (i < _origin.size() - 1) {
                std::cout << " ";
            }
            else {
                std::cout << std::endl;
            }
        }
    }
    std::cout << "After:  ";
    if (_vector.size() > 5) {
        for (unsigned int i = 0; i < 4; i++) {
            std::cout << _vector[i] << " ";
        }
        std::cout << "[...]" << std::endl;
    }
    else {
        for (unsigned int i = 0; i < _vector.size(); i++) {
            std::cout << _vector[i];
            if (i < _vector.size() - 1) {
                std::cout << " ";
            }
            else {
                std::cout << std::endl;
            }
        }
    }
    std::cout << std::fixed;
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << tempsVector << " s" << std::endl;
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << tempsDeque << " s" << std::endl;
}

void PmergeMe::setNumberVector() {
    for (unsigned int i = 0; i < _origin.size(); i++) {
        _vector.push_back(_origin[i]);
    }
    sortVector(_vector);
}

void PmergeMe::sortVector(std::vector<int> &vector) {
    std::vector<int> left;
    std::vector<int> right;
    if (vector.size() > 5) {
        for (unsigned int i = 0; i < vector.size(); i++) {
            if (i < (vector.size() / 2)) {
                left.push_back(vector[i]);
            }
            else {
                right.push_back(vector[i]);
            }
        }
        sortVector(left);
        sortVector(right);
        mergeVector(vector, left, right);
    }
    else {
        insertSortVector(vector);
    }
}

void PmergeMe::insertSortVector(std::vector<int> &vector) {
    for (unsigned int i = 0; i < vector.size() - 1; i++) {
        unsigned int j = i + 1;
        int temp = vector[j];
        while (j > 0 && temp < vector[j - 1]) {
            vector[j] = vector[j - 1];
            j--;
        }
        vector[j] = temp; 
    }
}

void PmergeMe::mergeVector(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right) {
    unsigned int indexLeft = 0;
    unsigned int indexRight = 0;
    for (unsigned int i = 0; i < vector.size(); i++) {
        if (indexLeft == left.size()) {
            vector[i] = right[indexRight++];
        }
        else if (indexRight == right.size()) {
            vector[i] = left[indexLeft++];
        }
        else if (right[indexRight] > left[indexLeft]) {
            vector[i] = left[indexLeft++];
        }
        else {
            vector[i] = right[indexRight++];
        }
    }
}

bool PmergeMe::isSortedVector(std::vector<int> &vector) {
    for (size_t i = 1; i < vector.size(); ++i) {
        if (vector[i] < vector[i - 1]) {
            return false;
        }
    }
    return true;
}

void PmergeMe::setNumberDeque() {
    for (unsigned int i = 0; i < _origin.size(); i++) {
        _deque.push_back(_origin[i]);
    }
    sortDeque(_deque);
}

void PmergeMe::sortDeque(std::deque<int> &deque) {
    std::deque<int> left;
    std::deque<int> right;
    if (deque.size() > 5) {
        for (unsigned int i = 0; i < deque.size(); i++) {
            if (i < (deque.size() / 2)) {
                left.push_back(deque[i]);
            }
            else {
                right.push_back(deque[i]);
            }
        }
        sortDeque(left);
        sortDeque(right);
        mergeDeque(deque, left, right);
    }
    else {
        insertSortDeque(deque);
    }
}

void PmergeMe::insertSortDeque(std::deque<int> &deque) {
    for (unsigned int i = 0; i < deque.size() - 1; i++) {
        unsigned int j = i + 1;
        int temp = deque[j];
        while (j > 0 && temp < deque[j - 1]) {
            deque[j] = deque[j - 1];
            j--;
        }
        deque[j] = temp; 
    }
}

void PmergeMe::mergeDeque(std::deque<int> &deque, std::deque<int> &left, std::deque<int> &right) {
    unsigned int indexLeft = 0;
    unsigned int indexRight = 0;
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (indexLeft == left.size()) {
            deque[i] = right[indexRight++];
        }
        else if (indexRight == right.size()) {
            deque[i] = left[indexLeft++];
        }
        else if (right[indexRight] > left[indexLeft]) {
            deque[i] = left[indexLeft++];
        }
        else {
            deque[i] = right[indexRight++];
        }
    }
}

bool PmergeMe::isSortedDeque(std::deque<int> &deque) {
    for (size_t i = 1; i < deque.size(); ++i) {
        if (deque[i] < deque[i - 1]) {
            return false;
        }
    }
    return true;
}