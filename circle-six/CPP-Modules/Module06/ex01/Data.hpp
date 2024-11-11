/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:29:31 by akastler          #+#    #+#             */
/*   Updated: 2023/10/17 17:39:39 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
    private:
        std::string s1;
        std::string s2;
        Data(Data const & src);
        Data &      operator=(Data const & rhs);
    
    public:
        Data();
        ~Data();
        std::string getString(int i) const;
        void        setString(std::string s1, int i);
};

#endif