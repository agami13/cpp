/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:17:55 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/29 20:38:04 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon){
}

void HumanA::attack() {
	std::cout << this->_name << " attacks with their " << _weapon.getType() << std::endl;
}

HumanA::~HumanA() {
}
