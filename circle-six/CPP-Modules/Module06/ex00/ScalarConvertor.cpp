/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:19:24 by akastler          #+#    #+#             */
/*   Updated: 2023/10/30 09:18:59 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertor.hpp"
#include <cctype>
#include <cstdlib>
#include <sstream>

//constructors

ScalarConvertor::ScalarConvertor( void ) : _str("42"), _type(INT) {
    return ;
}

ScalarConvertor::ScalarConvertor( std::string const & str ) : _type(UNDEF) {
    if (str == "") {
        _type = NAND;
        _str = "nan";
        return ;
    }
    std::string types[] = {"nan", "-inf", "+inf", ""};
    for (int i = 0; i < 4; i++) {
        if (types[i] == str) {
            _type = NAND;
        }
    }
    if (_type != NAND)
    {
        std::string types[] = {"nanf", "-inff", "+inff", ""};
        for (int i = 0; i < 4; i++) {
            if (types[i] == str) {
                _type = NANFD;
            }
        }
    }
    _str = str;
    return ;
}

void ScalarConvertor::convert(std::string const str) {
    ScalarConvertor scale(str);
    {
        try {
            if (scale.getType() == UNDEF)
                scale.findType();
            if (scale.getType() == INT)
                scale.checkInt();
            type Type = scale.getType();
            switch (Type)
            {
                case NAND:
                case NANFD:
                    scale.castToNanNand();
                case CHAR:
                    scale.castToChar();
                case INT:
                    scale.castToInt();
                case DOUBLE:
                    scale.castToDouble();
                case FLOAT:
                    scale.castToFloat();
                default:
                    break;
            }
        }
        catch (PrintedException & e) {
            // scale.printInfos();
        }
        catch (std::exception & e) {
            std::cout << e.what() << std::endl;
        }
    }
    return ;
}

// cast functions

void ScalarConvertor::castToNanNand() const {
    if (getType() == NAND) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << getStr() + "f" << std::endl;
        std::cout << "double: " << getStr() << std::endl;
    }
    else if (getType() == NANFD) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << getStr() << std::endl;
        std::cout << "double: " << getStr().substr(0, getStr().length() - 1) << std::endl;
    }
    throw PrintedException();
}

void ScalarConvertor::castToChar() const {
    char for_cast = getStr()[0];
    if (static_cast<char>(for_cast) <= 32 || static_cast<char>(for_cast) > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << for_cast << std::endl;
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "int: " << static_cast<int>(for_cast) << std::endl;
    std::cout << "float: " << static_cast<float>(for_cast) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(for_cast) << std::endl;
    throw PrintedException();
}

void ScalarConvertor::castToInt() const {
    int for_cast = std::atoi(getStr().c_str());
    std::cout << "char: ";
    if (static_cast<char>(for_cast) <= 32 || static_cast<char>(for_cast) > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(for_cast) << std::endl;
    std::cout << std::fixed;
    std::cout.precision(1);
    std::cout << "int: " << static_cast<int>(for_cast) << std::endl;
    std::cout << "float: " << static_cast<float>(for_cast) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(for_cast) << std::endl;
    throw PrintedException();
}

void ScalarConvertor::castToFloat() const {
    float for_cast = std::strtof(getStr().c_str(), 0);
    std::cout << "char: ";
    if (static_cast<char>(for_cast) <= 32 || static_cast<char>(for_cast) > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(for_cast) << std::endl;
    std::cout << "int: " << static_cast<int>(for_cast) << std::endl;
    if (static_cast<int>(for_cast) == static_cast<float>(for_cast)) {
        std::cout << std::fixed;
        std::cout.precision(1);
    }
    std::cout << "float: " << static_cast<float>(for_cast) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(for_cast) << std::endl;
    throw PrintedException();
}

void ScalarConvertor::castToDouble() const {
    double for_cast = std::strtod(getStr().c_str(), 0);
    std::cout << "char: ";
    if (static_cast<char>(for_cast) <= 32 || static_cast<char>(for_cast) > 126)
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(for_cast) << std::endl;
    std::cout << "int: " << static_cast<int>(for_cast) << std::endl;
    if (static_cast<int>(for_cast) == static_cast<double>(for_cast)) {
        std::cout << std::fixed;
        std::cout.precision(1);
    }
    std::cout << "float: " << static_cast<float>(for_cast) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(for_cast) << std::endl;
    throw PrintedException();
}

//function to find the type

void ScalarConvertor::findType() {
    std::string origin = this->getStr();
    if (origin.length() == 1) {
        if (std::isdigit(origin[0]))
            _type = INT;
        else
            _type = CHAR;
    }
    else {
        if (checkValid() == false) {
            throw InvalidInputException();
        }
        if (origin.find_first_of('.') == std::string::npos) {
            if (origin.find_first_of('f') == std::string::npos) {
                _type = INT;
            }
            else {
                _type = FLOAT;
            }
        }
        else {
            if (origin.find_first_of('f') == std::string::npos) {
                _type = DOUBLE;
            }
            else {
                _type = FLOAT;
            }
        }
    }
}

//function to check the validity

bool ScalarConvertor::checkValid() const {
    std::string origin = this->getStr();
    int point = 0;
    for (size_t i = 0; i < origin.length(); i++) {
        if (origin[i] == '-' || origin[i] == '+') {
            if (i != 0)
                return (false);
        }
        else if (origin[i] == '.') {
            if (i == 0 || i == origin.length() - 1 || point == 1)
                return (false);
            else if (( origin[i - 1] && std::isdigit(origin[i - 1]) == false)
                    || (origin[i + 1] && (std::isdigit(origin[i + 1]) == false && origin[i + 1] != 'f')))
                return (false);
            point = 1;
        }
        else if (origin[i] == 'f') {
            if (i != origin.length() - 1 || point == 0)
                return (false);
        }
        else if (std::isdigit(origin[i]) == false)
            return (false);
    }
    return (true);
}

void ScalarConvertor::checkInt() {
    std::string origin = this->getStr();
    if (origin.length() >= 12) {
        _type = DOUBLE;
        return ;
    }
    else if (origin.length() == 11 || origin.length() == 10) {
        long int test = std::strtol(origin.c_str(), 0, 0);
        if (test < -2147483648 || test > 2147483647) {
            _type = DOUBLE;
            return ;
        }
    }
}

// getters

std::string const & ScalarConvertor::getStr( void ) const {
    return _str;
}

type ScalarConvertor::getType( void ) const {
    return _type;
}

ScalarConvertor::ScalarConvertor( ScalarConvertor const & src ) {
    (void)src;
    return ;
}

ScalarConvertor::~ScalarConvertor( void ) {
    return ;
}

ScalarConvertor & ScalarConvertor::operator=( ScalarConvertor const & rhs ) {
    (void)rhs;
    return *this;
}

void ScalarConvertor::printInfos() const {
    std::string temp;
    std::cout << std::endl << "Do you want to see the information of the execution ? (y/n)" << std::endl;
    std::getline(std::cin, temp);
    if (std::cin.eof() || (temp != "y" && temp != "Y"))
        return;
    std::cout << std::endl << "Information of the execution :" << std::endl;
    std::cout << " type: ";
    switch (getType())
    {
        case NANFD:
            std::cout << "nanf" << std::endl;
            break;
        case NAND:
            std::cout << "nan" << std::endl;
            break;
        case CHAR:
            std::cout << "char" << std::endl;
            break;
        case INT:
            std::cout << "int" << std::endl;
            break;
        case DOUBLE:
            std::cout << "double" << std::endl;
            break;
        case FLOAT:
            std::cout << "float" << std::endl;
            break;
        default:
            break;
    }
    std::cout << "value: " << getStr() << std::endl;
}