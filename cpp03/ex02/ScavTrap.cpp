/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 17:51:43 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/10 16:47:19 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "ScavTrap " << _name << " has been created!" << std::endl;

}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {

	if (_hitPoints > 0 && _energyPoints > 0) {
		std::cout << "ScavTrap " << _name << " ferociously attacks " << target << ", causing " 
		          << _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of hit points!" << std::endl;
	}
	else if (_energyPoints == 0) {
		std::cout << "ScavTrap " << _name << " is out of energy points!" << std::endl;
	}

}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << _name << " is now in Gate Keeper mode!" << std::endl;
}
