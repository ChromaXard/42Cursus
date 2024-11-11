/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:38:37 by akastler          #+#    #+#             */
/*   Updated: 2023/11/03 13:45:22 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array {
    public:
        class OutOfBoundsException : public std::exception {
            public:
                virtual const char* what() const throw() {
                    return ("Index is out of bounds");
                }
        };
        Array<T>() : _values(new T[0]), _size(0) {}
        
        Array<T>(unsigned int i) : _values(new T[i]), _size(i) {}
        
        Array<T>(Array<T> const &src) : _values(new T[src._size]), _size(src._size) {
            for (unsigned int i = 0; i < src._size; i++)
                _values[i] = src._values[i];
        }
        
        Array<T> &operator=(Array<T> const &src) {
            delete[] _values;
            _values = new T[src._size];
            _size = src._size;
            for (unsigned int i = 0; i < src._size; i++)
                _values[i] = src._values[i];
        }

        T &operator[](unsigned int index) {
            if (index >= _size || index < 0) {
                throw (Array::OutOfBoundsException());
            }
            return (_values[index]);
        }

        ~Array<T>() {
            delete[] _values;
        }

    private:

        T *_values;
        unsigned int _size;
};