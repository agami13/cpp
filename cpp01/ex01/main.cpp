/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 02:24:14 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 23:45:48 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	
	Zombie *newZ;

	newZ = zombieHorde(5, "Zombie");
	
	for (int i = 0; i < 5; i++)
		newZ[i].announce();
	
	delete [] newZ;
	return (0);

}
