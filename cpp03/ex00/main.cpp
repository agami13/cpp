/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:38:20 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/09 17:49:00 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap claptrap("Sassy");

	claptrap.attack("target1");
	claptrap.takeDamage(9);
	claptrap.beRepaired(9);
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	claptrap.takeDamage(9);
	claptrap.beRepaired(9);
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	claptrap.takeDamage(9);
	claptrap.beRepaired(9);
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	claptrap.takeDamage(9);
	claptrap.beRepaired(9);
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	claptrap.takeDamage(9);
	claptrap.beRepaired(9);
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	claptrap.beRepaired(9);
	claptrap.takeDamage(1);
	claptrap.beRepaired(1);
	claptrap.attack("target1");
	claptrap.attack("target2");
	claptrap.attack("target3");
	return (0);
}