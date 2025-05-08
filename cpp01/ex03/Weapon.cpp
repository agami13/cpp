/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:18:14 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/29 20:39:02 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) {
	this->_type = type;
}

std::string Weapon::getType() {
	return (this->_type);
}

void Weapon::setType(std::string type) {
	this->_type = type;
}

Weapon::~Weapon() {
}
