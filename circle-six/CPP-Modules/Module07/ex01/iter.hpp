/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 11:03:29 by axel              #+#    #+#             */
/*   Updated: 2023/11/07 18:14:24 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <typename A>
void print(A const &a)
{
    std::cout << a << " ";
}

/*
Iter function is a function takes 3 arguments:
- an array
- the length of the array
- a function pointer that takes a reference to an element of the array as a parameter

The iter function applies the function pointer to each element of the array.
The max length for length argument is the max value of int
If the length is negative, the function does nothing.
*/
template <typename A, typename F>
void iter(A *adress, int length, F function)
{
    if (length < 0)
        return ;
    for (int i = 0; i < length; i++)
        function(*adress++);
}

#endif