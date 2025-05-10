/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:39:31 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/10 16:23:13 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " has been created!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << _name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target) {

	if (_hitPoints == 0)
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
	else if (_energyPoints == 0)
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;
	else if (_energyPoints > 0 && _hitPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
		<< _attackDamage << " points of damage!" << std::endl;
		_energyPoints--;
	}

}

void ClapTrap::takeDamage(unsigned int amount) {

	if (_hitPoints > 0) {
		_hitPoints -= amount;
		if (_hitPoints < 0)
			_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage! "
			<< "Hit points left: " << _hitPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount) {

	if (_hitPoints > 0 && _energyPoints > 0) {
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repairs itself for " << amount
			<< " hit points! Hit points now: " << _hitPoints << std::endl;
		_energyPoints--;
	}
	else if (_hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is already destroyed!" << std::endl;
	else
		std::cout << "ClapTrap " << _name << " is out of energy!" << std::endl;

}
