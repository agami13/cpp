/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:24:29 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/07/07 14:27:37 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <string>

class Fixed{
	private:
		int					_FIXED_INT;
		static const int	_FRAC_BITS = 8;

	public:
		// Constructors
		Fixed();

		// Copy constructor
		Fixed( const Fixed& copy );

		// Destructor
		~Fixed();

		// Assignment operator
		Fixed& operator=( const Fixed& copy );

		// member functions
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};

#endif