/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:30:22 by akastler          #+#    #+#             */
/*   Updated: 2023/12/04 15:45:31 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>

class RPN {
    public:
        RPN(void);
        RPN(RPN const &src);
        ~RPN(void);

        RPN &operator=(RPN const &src);

        void treatString(std::string const &str);
        
    private:
        void applyOperator(std::string const &oper);
        void checkErrors(std::string const &src);
        std::stack<long long int> _numbers;
};