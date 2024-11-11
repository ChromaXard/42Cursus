/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertor.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:11:34 by akastler          #+#    #+#             */
/*   Updated: 2023/10/30 09:01:36 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTOR_HPP
# define SCALARCONVERTOR_HPP

# include <iostream>

typedef enum e_type
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    NAND,
    NANFD,
    UNDEF
}   type;

class ScalarConvertor
{
    private:
        std::string         _str;
        type                _type;
        ScalarConvertor( void );
        ScalarConvertor( std::string const & str );
        ScalarConvertor( ScalarConvertor const & src );
        ~ScalarConvertor( void );

        ScalarConvertor & operator=( ScalarConvertor const & rhs );
        std::string const & getStr( void ) const;
        type getType( void ) const;
        void findType( void );
        bool checkValid( void ) const;
        void checkInt( void );

        void castToChar( void ) const ;
        void castToInt( void ) const ;
        void castToFloat( void ) const ;
        void castToDouble( void ) const ;
        void castToNanNand( void ) const ;

        void printInfos( void ) const;

        class InvalidInputException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return ("Invalid input");
                }
        };
        class PrintedException : public std::exception
        {
            public:
                virtual const char* what() const throw() {
                    return ("");
                }
        };
    public:
        static void convert(std::string const str);
};

#endif