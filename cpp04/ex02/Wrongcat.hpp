/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Wrongcat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:46:44 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/12 18:51:31 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "Animal.hpp"

class WrongAnimal {

	protected:
		std::string	type;

	public:
		WrongAnimal();
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		void makeSound() const;
		std::string getType() const;

};

class WrongCat : public WrongAnimal {

	public:
		WrongCat();
		~WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		void makeSound() const;

};


#endif