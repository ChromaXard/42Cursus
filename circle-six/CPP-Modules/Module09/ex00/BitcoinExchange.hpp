/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:39:37 by akastler          #+#    #+#             */
/*   Updated: 2023/12/04 15:26:33 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <map>

class BitcoinExchange {
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange &operator=(BitcoinExchange const &rhs);

        void    setData(std::string data);
        void    readInput(std::string const &src);
        void    printData();
    
    private:
        std::string findSyntax(std::string const &str, std::string const &val1, std::string const &val2);
        bool        checkMonthDay(int month, int day, int year);
        int         verifyDateRate(std::string const &date);
        void        addZeroifNeed(std::string &date, unsigned int line);
        bool        verifyErrorForContinue(int yearCheck, int monthCheck, int dayCheck, std::string const &date, unsigned int line);
        bool        verifyNumber(std::string &number);
        
        std::map<std::string, float> _data;
};