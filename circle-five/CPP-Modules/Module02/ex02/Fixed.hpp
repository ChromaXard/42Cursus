/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akastler <akastler@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:46:29 by akastler          #+#    #+#             */
/*   Updated: 2023/09/22 11:28:12 by akastler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	public:
		Fixed(void);
		Fixed(Fixed const & src);
		Fixed(int const n);
		Fixed(float const n);
		~Fixed(void);

		/*arithmetic operator*/
		Fixed&				operator=(Fixed const & rhs);
		Fixed				operator+(Fixed const & rhs) const;
		Fixed				operator-(Fixed const & rhs) const;
		Fixed				operator*(Fixed const & rhs) const;
		Fixed				operator/(Fixed const & rhs) const;
		/*increment operator*/
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
		/*comparaison operator*/
		bool				operator>(Fixed const & rhs) const;
		bool				operator<(Fixed const & rhs) const;
		bool				operator>=(Fixed const & rhs) const;
		bool				operator<=(Fixed const & rhs) const;
		bool				operator==(Fixed const & rhs) const;
		bool				operator!=(Fixed const & rhs) const;

		/*static function (min and max)*/
		static Fixed&		min(Fixed & a, Fixed & b);
		static Fixed const&	min(Fixed const & a, Fixed const & b);
		static Fixed&		max(Fixed & a, Fixed & b);
		static Fixed const&	max(Fixed const & a, Fixed const & b);

		/*member function*/
		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		int					toInt(void) const;
		float				toFloat(void) const;

	private:
		int					_raw;
		static const int	_bits = 8;
};

/*overload insertion*/
std::ostream& operator<<(std::ostream& o, Fixed const & rhs);

#endif