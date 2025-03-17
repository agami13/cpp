/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:17:55 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 19:55:40 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) {
	this->name = name;
	this->weapon = &weapon;
}

void HumanA::setWeapon(Weapon &weapon) {
	this->weapon = &weapon;
}

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}
