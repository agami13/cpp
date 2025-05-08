/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:34:20 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/29 20:40:15 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
}

HumanB::~HumanB() {
}

void HumanB::setWeapon(Weapon &weapon) {
	this->_weapon = &weapon;
}

void HumanB::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
