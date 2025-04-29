/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:24:14 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/28 14:49:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	
	Zombie *newZ;

	newZ = newZombie("Zombie2");
	newZ->announce();
	delete newZ;

	randomChump("Zombie1");
	return (0);

}
