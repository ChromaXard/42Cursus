/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:10:22 by akastler          #+#    #+#             */
/*   Updated: 2023/11/16 11:03:36 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
    public:
        MutantStack() {}
        MutantStack(MutantStack const & src) { *this = src; }
        ~MutantStack() {}
        MutantStack & operator=(MutantStack const & rhs) {
            if (*this != rhs) {
                this->c = rhs.c;
            }
            return *this;
        }
        
        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator begin() { 
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }

};