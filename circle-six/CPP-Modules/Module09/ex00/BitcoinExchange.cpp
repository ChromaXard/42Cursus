/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 17:39:45 by akastler          #+#    #+#             */
/*   Updated: 2023/12/08 11:08:12 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <exception>
#include <sstream>
#include "BitcoinExchange.hpp"

#define RED "\033[0;31m";
#define GREEN "\033[0;32m";
#define YELLOW "\033[0;33m";
#define RESET "\033[0m";

BitcoinExchange::BitcoinExchange() {
    return ;
}

BitcoinExchange::~BitcoinExchange() {
    return ;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
    *this = src;
    return ;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &rhs) {
    if (this != &rhs) {
        this->_data = rhs._data;
    }
    return *this;
}

std::string BitcoinExchange::findSyntax(std::string const &str, std::string const &val1, std::string const &val2) {
    std::string ret;
    if (str.empty() || str.length() == 0 || str.find(val1) == std::string::npos || str.find(val2) == std::string::npos)
        return ("");
    if (str.find(val1) > str.find(val2)) {
        ret =  str.substr(str.find(val2) + val2.length());
        ret = ret.substr(0, ret.find(val1));
    }
    else {
        ret =  str.substr(str.find(val1) + val1.length());
        ret = ret.substr(0, ret.find(val2));
    }
    return(ret);
}

int BitcoinExchange::verifyDateRate(std::string const &date) {
    {
        int hyphen = 0;
        int place = 0;
        int lenPlace[3] = {0, 0, 0};
        for (unsigned int i = 0; i < date.length(); i++) {
            if (place == 0 && date[i] != '-') {
                if (date[i] < '0' || date[i] > '9' || lenPlace[0] > 4)
                    return (1);
                lenPlace[0]++;
            }
            else if (place == 1 && date[i] != '-') {
                if (date[i] < '0' || date[i] > '9' || lenPlace[1] > 2 || lenPlace[0] != 4)
                    return(1);
                lenPlace[1]++;
            }
            else if (place == 2 && date[i] != '-') {
                if (date[i] < '0' || date[i] > '9' || lenPlace[2] > 2 || lenPlace[0] != 4)
                    return(1);
                lenPlace[2]++;
            }
            if (date[i] == '-') {
                if (hyphen == 2) {
                    return (1);
                }
                hyphen++;
                place++;
            }
        }
        if (hyphen != 2 || lenPlace[0] == 0 || lenPlace[1] == 0 || lenPlace[2] == 0)
            return (1);
        else if (lenPlace[1] == 1 && lenPlace[2] == 1)
            return(2);
        else if (lenPlace[1] == 1)
            return (3);
        else if (lenPlace[2] == 1)
            return (4);
    }
    return (0);
}

bool BitcoinExchange::checkMonthDay(int month, int day, int year) {
    if (day >= 32 || month >= 13)
        return false;
    else if (month == 2) {
        if (day > 29)
            return false;
        if (day == 29) {
            int test[3];
            test[0] = (year % 4 == 0);
            test[1] = (year % 100 != 0);
            test[2] = (year % 400 == 0);
            int fin = test[0] + test[1] + test[2];
            if (fin != 2)
                return false;
        }
        return true;
    }
    else if (day == 31) {
        if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
            return false;
        return true;
    }
    else
        return true;
}

void BitcoinExchange::addZeroifNeed(std::string &date, unsigned int line) {
    int verify = verifyDateRate(date);
    if (verify == 1) {
        std::ostringstream iss;
        iss << "BitcoinExchange: Error: invalid date format at line " << line;
        throw std::logic_error(iss.str());
    }
    else if (verify == 2) {
        date.insert(date.find_first_of('-') + 1, 1, '0');
        date.insert(date.find_last_of('-') + 1, 1, '0');
    }
    else if (verify == 3) {
        date.insert(date.find_first_of('-') + 1, 1, '0');
    }
    else if (verify == 4) {
        date.insert(date.find_last_of('-') + 1, 1, '0');
    }
}

bool BitcoinExchange::verifyNumber(std::string &number) {
    int dot = 0;
    if (number.empty() || number.length() == 0)
        return false;
    for (unsigned int i = 0; i < number.length(); i++) {
        if (std::isdigit(number[i])) {
            continue ;
        }
        else{
            if (number[i] == '.' && dot == 0) {
                dot++;
                if (number[i + 1] && std::isdigit(number[i + 1]))
                    continue;
            }
            return false;
        }
    }
    return true;
}

void BitcoinExchange::setData(std::string data) {
    if (data.empty() || data.length() == 0){
        std::cerr << "data is empty" << std::endl;
        return ;
    }
    if (data.find(".csv") == std::string::npos || data.find(".csv") != data.length() - 4) {
        std::cerr << "invalid extension" << std::endl;
        return ;
    }
    std::ifstream dataFile(data.c_str());
    if (dataFile.is_open()) {
        std::string lastRead;
        std::string before;
        std::string after;
        std::string syntax[2];
        int i = 0;
        unsigned int line = 2;
        while(1) {
            if (dataFile.eof())
                break;
            std::getline(dataFile, lastRead);
            if (lastRead.length() == 0) {
                line++;
                continue;
            }
            if (i == 0) {
                syntax[0] = findSyntax(lastRead, "date", "exchange_rate");
                syntax[1] = lastRead.substr(0, lastRead.find(syntax[0]));
                if (syntax[0].empty() || syntax[0].length() == 0) {
                    throw std::logic_error("BitcoinExchange: Error: invalid syntax");
                }
                i++;
                continue;
            }
            if (lastRead.find(syntax[0]) == std::string::npos) {
                std::ostringstream iss;
                iss << "BitcoinExchange: Error: invalid syntax detected at line " << line;
                throw std::logic_error(iss.str());
            }
            if (syntax[1] == "date") {
                before = lastRead.substr(0, lastRead.find(syntax[0]));
                after = lastRead.substr(lastRead.find(syntax[0]) + syntax[0].length(), lastRead.length());
                addZeroifNeed(before, line);
                if (verifyNumber(after) == false){
                    std::ostringstream ss;
                    ss << "BitcoinExchange: Error: exchange rate is not a number at line " << line;
                    throw std::logic_error(ss.str());
                }
                _data[before] = std::strtof(after.c_str(), 0);
            }
            else {
                before = lastRead.substr(0, lastRead.find(syntax[0]));
                after = lastRead.substr(lastRead.find(syntax[0]) + syntax[0].length(), lastRead.length());
                addZeroifNeed(after, line);
                if (verifyNumber(before) == false){
                    std::ostringstream ss;
                    ss << "BitcoinExchange: Error: exchange rate is not a number at line " << line;
                    throw std::logic_error(ss.str());
                }
                _data[after] = std::strtof(before.c_str(), 0);
            }
            lastRead.clear();
            line++;
        }
        dataFile.close();
        if (_data.size() == 0)
            throw std::logic_error("BitcoinExchange: Error: no data");
        for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
            std::string checkthis = it->first;
            int yearCheck = std::atoi(checkthis.substr(0, checkthis.find_first_of("-")).c_str());
            int monthCheck = std::atoi(checkthis.substr(checkthis.find_first_of("-") + 1, 2).c_str());
            int dayCheck = std::atoi(checkthis.substr(checkthis.find_last_of("-") + 1, 2).c_str());
            if (yearCheck == 0 || monthCheck == 0 || dayCheck == 0)
                throw std::logic_error("BitcoinExchange: Error: invalid date in data") ;
            std::time_t t = std::time(NULL);
            std::tm* now = std::localtime(&t);
            int year = (now->tm_year + 1900);
            int month = (now->tm_mon + 1);
            int day = now->tm_mday;
            if (yearCheck > year)
                throw std::logic_error("BitcoinExchange: Error: invalid date in data");
            else if (yearCheck == year) {
                if (monthCheck > month)
                    throw std::logic_error("BitcoinExchange: Error: invalid date in data");
                else if (monthCheck == month) {
                    if (dayCheck > day)
                        throw std::logic_error("BitcoinExchange: Error: invalid date in data");
                }
            }
            if (yearCheck == 2008) {
                if (monthCheck == 8) {
                    if (dayCheck < 18)
                        throw std::logic_error("BitcoinExchange: Error: invalid date in data") ;
                }
                else if (monthCheck < 8)
                    throw std::logic_error("BitcoinExchange: Error: invalid date in data") ;
            }
            else if (yearCheck < 2008)
                throw std::logic_error("BitcoinExchange: Error: invalid date in data") ;
            if (checkMonthDay(monthCheck, dayCheck, yearCheck) == false)
                throw std::logic_error("BitcoinExchange: Error: invalid date in data") ;
        }
    }
    else {
        throw std::logic_error("BitcoinExchange: Error: cannot open data file");
    }
}

void BitcoinExchange::readInput(std::string const &src) {
    std::cout << YELLOW;
    if (src.empty() || src.size() == 0)
        throw std::logic_error("BitcoinExchange: Error: invalid input file");
    std::ifstream inputFile(src.c_str());
    if (inputFile.is_open()) {
        std::string Read;
        std::string syntax[2];
        std::getline(inputFile, Read);
        if (Read.empty() || Read.length() == 0)
            throw std::logic_error("BitcoinExchange: Error: input file is empty");
        std::cout << RED;
        syntax[0] = findSyntax(Read, "date", "value");
        if (syntax[0].empty() || syntax[0].length() == 0)
            throw std::logic_error("BitcoinExchange: Error: invalid syntax in input file");
        syntax[1] = Read.substr(0, Read.find(syntax[0]));
        if (syntax[1].empty() || syntax[1].length() == 0)
            throw std::logic_error("BitcoinExchange: Error: invalid syntax in input file");
        std::string before;
        std::string after;
        int lineNbr = 1;
        while(1) {
            std::cout << YELLOW;
            ++lineNbr;
            if (inputFile.eof())
                break;
            std::getline(inputFile, Read);
            if (Read.length() == 0)
                continue;
            if (Read.find(syntax[0]) == std::string::npos) {
                std::cout << "BitcoinExchange: Error: bad input (missing separator : \"" << syntax[0] << "\") => " << Read  << " (Line number : " << lineNbr << ")"<< std::endl;
                continue;
            }
            else {
                before = Read.substr(0, Read.find(syntax[0]));
                after = Read.substr(Read.find(syntax[0]) + syntax[0].length(), Read.length());
                std::string date;
                float value;
                if (syntax[1] == "date") {
                    addZeroifNeed(before, lineNbr);
                    date = before;
                    if (verifyNumber(after) == false) {
                        std::cout << "BitcoinExchange: Error: Not a valid value (character detected) => " << Read << " (Line number : " << lineNbr << ")" << std::endl;
                        continue ;
                    }
                    value = std::strtod(after.c_str(), 0);
                }
                else {
                    addZeroifNeed(after, lineNbr);
                    date = after;
                    value = std::strtof(before.c_str(), 0);
                }
                int yearCheck = std::atoi(date.substr(0, date.find_first_of("-")).c_str());
                int monthCheck = std::atoi(date.substr(date.find_first_of("-") + 1, 2).c_str());
                int dayCheck = std::atoi(date.substr(date.find_last_of("-") + 1, 2).c_str());
                if (verifyErrorForContinue(yearCheck, monthCheck, dayCheck, date, lineNbr) == true)
                    continue;
                else if (value < 0) {
                    std::cout << "BitcoinExchange: Error: not a positive number => " << Read << " (Line number : " << lineNbr << ")" << std::endl;
                    continue;
                }
                else if (value > 1000) {
                    std::cout << "BitcoinExchange: Error: too large a number => " << Read << " (Line number : " << lineNbr << ")" << std::endl;
                    continue;
                }
                if (date < _data.begin()->first) {
                    std::cout << "BitcoinExchange: Error: date out of range => " << Read << " (Line number : " << lineNbr << ")" << std::endl;
                    continue;
                }
                std::map<std::string, float>::iterator it = _data.find(date);
                if (it == _data.end()) {
                    it = _data.upper_bound(date);
                    it--;
                }
                std::cout << GREEN;
                std::cout << date << " => " << value << " = " <<  value * it->second << std::endl;
            }
        }
        
    }
    else {
        throw std::logic_error("BitcoinExchange: Error: cannot open input file");
    }
}

void BitcoinExchange::printData() {
    std::cout << YELLOW;
    for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }
}

bool BitcoinExchange::verifyErrorForContinue(int yearCheck, int monthCheck, int dayCheck, std::string const &Read, unsigned int lineNbr) {
    if (yearCheck == 0 || monthCheck == 0 || dayCheck == 0) {
        std::cout << "BitcoinExchange: Error: bad input (invalid date) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
        return true;
    }
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);
    int year = (now->tm_year + 1900);
    int month = (now->tm_mon + 1);
    int day = now->tm_mday;
    if (yearCheck > year) {
        std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
        return true;
    }
    else if (yearCheck == year) {
        if (monthCheck > month){
            std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
            return true;
        }
        else if (monthCheck == month) {
            if (dayCheck > day) {
                std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
                return true;
            }
        }
    }
    if (yearCheck == 2008) {
        if (monthCheck == 8) {
            if (dayCheck < 18) {
                std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
                return true;
            }
        }
        else if (monthCheck < 8){
            std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
            return true;
        }
    }
    else if (yearCheck < 2008) {
        std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
        return true;
    }
    if (checkMonthDay(monthCheck, dayCheck, yearCheck) == false){
        std::cout << "BitcoinExchange: Error: Bad input (date is not valid) => " << Read << " (Line number : " << lineNbr << ")"<< std::endl;
        return true;
    }
    return false;
}