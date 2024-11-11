/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:41:38 by akastler          #+#    #+#             */
/*   Updated: 2023/11/28 15:26:35 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>

class PmergeMe {
    public:
        PmergeMe(void);
        PmergeMe(PmergeMe const & src);
        ~PmergeMe(void);

        PmergeMe & operator=(PmergeMe const & rhs);

        void add(int n);
        void check(std::string str);
        void launchProcess(void);
        void printResultProcess(double tempsVector, double tempsDeque);
        
        void setNumberVector();
        void sortVector(std::vector<int> &vector);
        void insertSortVector(std::vector<int> &vector);
        void mergeVector(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right);
        bool isSortedVector(std::vector<int> &vector);
        
        void setNumberDeque();
        void sortDeque(std::deque<int> &deque);
        void insertSortDeque(std::deque<int> &deque);
        void mergeDeque(std::deque<int> &deque, std::deque<int> &left, std::deque<int> &right);
        bool isSortedDeque(std::deque<int> &deque);
    private:
        std::deque<int> _deque;
        std::vector<int> _vector;

        std::vector<int> _origin;
};