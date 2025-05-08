/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:59:50 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/08 14:42:57 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class Fixed {
	private:
		int					_FixedInt;
		static const int	_FractBits = 8;
	
	public:
		Fixed();
		Fixed( const int value );
		Fixed( const float value );
		
		Fixed( const Fixed& copy );
		
		~Fixed();
		
		Fixed& operator=( const Fixed& copy );
		
		float	toFloat( void ) const;
		int		toInt( void ) const;
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		static Fixed&	min( Fixed& a, Fixed& b );
		static const Fixed&	min( const Fixed& a, const Fixed& b );
		static Fixed&	max( Fixed& a,Fixed& b );
		static const Fixed&	max( const Fixed& a, const Fixed& b );
		
		bool operator>( const Fixed& op ) const;
		bool operator<( const Fixed& op ) const;
		bool operator<=( const Fixed& op ) const;
		bool operator>=( const Fixed& op ) const;
		bool operator!=( const Fixed& op ) const;
		bool operator==( const Fixed& op ) const;
		
		Fixed operator+( const Fixed& op ) const;
		Fixed operator-( const Fixed& op ) const;
		Fixed operator*( const Fixed& op ) const;
		Fixed operator/( const Fixed& op ) const;
		
		Fixed& operator++( void ); // prefix
		Fixed operator++( int ); // postfix
		Fixed& operator--( void ); // prefix
		Fixed operator--( int ); // postfix
};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed );

#endif