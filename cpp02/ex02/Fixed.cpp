/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:59:41 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/08 14:51:17 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _FixedInt(0){
}

Fixed::Fixed( const int value ) : _FixedInt(0) {
	_FixedInt = value << _FractBits;
}

Fixed::Fixed( const float value ) : _FixedInt(0) {
	_FixedInt = roundf(value * (1 << _FractBits));
}

Fixed::Fixed( const Fixed& copy ) {
	_FixedInt = copy._FixedInt;
}

Fixed& Fixed::operator=( const Fixed& copy ){
	if (this != &copy)
		this->_FixedInt = copy._FixedInt;
	return *this;
}

Fixed::~Fixed() {
}

float Fixed::toFloat( void ) const {
	return (float)_FixedInt / (1 << _FractBits);
}

int Fixed::toInt( void ) const {
	return _FixedInt >> _FractBits;
}

int Fixed::getRawBits( void ) const{
	return this->_FixedInt;
}

void Fixed::setRawBits( int const raw ){
	this->_FixedInt = raw;
}

std::ostream& operator<<( std::ostream& os, const Fixed& fixed ) {
	os << fixed.toFloat();
	return os;
}

Fixed& Fixed::min( Fixed& a, Fixed& b ) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max( Fixed& a, Fixed& b ) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::min( const Fixed& a, const Fixed& b ) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::max( const Fixed& a, const Fixed& b ) {
	return (a > b) ? a : b;
}

bool Fixed::operator>( const Fixed& op ) const {
	return _FixedInt > op._FixedInt;
}

bool Fixed::operator<( const Fixed& op ) const {
	return _FixedInt < op._FixedInt;
}

bool Fixed::operator<=( const Fixed& op ) const {
	return _FixedInt <= op._FixedInt;
}

bool Fixed::operator>=( const Fixed& op ) const {
	return _FixedInt >= op._FixedInt;
}

bool Fixed::operator!=( const Fixed& op ) const {
	return _FixedInt != op._FixedInt;
}

bool Fixed::operator==( const Fixed& op ) const {
	return _FixedInt == op._FixedInt;
}

Fixed Fixed::operator+( const Fixed& op ) const {
	Fixed result;
	result.setRawBits(this->_FixedInt + op._FixedInt);
	return result;
}

Fixed Fixed::operator-( const Fixed& op ) const {
	Fixed result;
	result.setRawBits(this->_FixedInt - op._FixedInt);
	return result;
}

Fixed Fixed::operator*( const Fixed& op ) const {
	Fixed result;
	result.setRawBits((this->_FixedInt * op._FixedInt) >> _FractBits);
	return result;
}

Fixed Fixed::operator/( const Fixed& op ) const {
	Fixed result;
	result.setRawBits((this->_FixedInt << _FractBits) / op._FixedInt);
	return result;
}

Fixed& Fixed::operator++( void ) {
	_FixedInt++;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed temp = *this;
	_FixedInt++;
	return temp;
}

Fixed& Fixed::operator--( void ) {
	_FixedInt--;
	return *this;
}

Fixed Fixed::operator--( int ) {
	Fixed temp = *this;
	_FixedInt--;
	return temp;
}