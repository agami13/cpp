/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:06:59 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/14 18:14:51 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _FIXED_INT(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed& copy ) : _FIXED_INT(copy._FIXED_INT){
	std::cout << "Copy constructor called" << std::endl;
	_FIXED_INT = copy._FIXED_INT;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=( const Fixed& copy ){
	std::cout << "Assignation operator called" << std::endl;
	if (this != &copy)
		this->_FIXED_INT = copy._FIXED_INT;
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_FIXED_INT;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_FIXED_INT = raw;
}
