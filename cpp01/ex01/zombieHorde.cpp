/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:02:46 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 20:47:24 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	
	Zombie *horde = new Zombie[N];
	for (int i = 0; i < N; i++)
		horde[i].SetZombie(name);
	return (horde);

}
