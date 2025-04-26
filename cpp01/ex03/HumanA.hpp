/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:17:58 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 20:47:50 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP


#include "Weapon.hpp"

class HumanA {
	
	private:
		std::string name;
		Weapon *weapon;
	
	public:
		void	attack();
		void	setWeapon(Weapon &weapon);
		HumanA(std::string name, Weapon &weapon);

};



#endif