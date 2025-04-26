/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:18:03 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 20:48:00 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP


#include "Weapon.hpp"

class HumanB {
	
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		void	attack();
		void	setWeapon(Weapon &weapon);
		HumanB(std::string name);

};


#endif