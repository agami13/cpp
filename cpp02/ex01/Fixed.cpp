/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:59:41 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/14 20:33:56 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _FixedInt(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int value ) : _FixedInt(0) {
	std::cout << "Int constructor called" << std::endl;
	_FixedInt = value << _FractBits;
}

Fixed::Fixed( const float value ) : _FixedInt(0) {
    std::cout << "Float constructor called" << std::endl;
	_FixedInt = roundf(value * (1 << _FractBits));
}

Fixed::Fixed( const Fixed& copy ) {
	std::cout << "Copy constructor called" << std::endl;
	_FixedInt = copy._FixedInt;
}

Fixed& Fixed::operator=( const Fixed& copy ){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		this->_FixedInt = copy._FixedInt;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const {
	return (float)_FixedInt / (1 << _FractBits);
}

int Fixed::toInt( void ) const {
	return _FixedInt >> _FractBits;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_FixedInt;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	this->_FixedInt = raw;
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed ) {
	os << fixed.toFloat();
	return os;
}
