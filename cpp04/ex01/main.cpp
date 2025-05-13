/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:15:21 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/12 18:54:19 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {


	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	Animal *animals[6];
	for (int i = 0; i < 3; i++)
		animals[i] = new Dog();
	for (int i = 3; i < 6; i++)
		animals[i] = new Cat();


	for (int i = 0; i < 6; i++) {
		animals[i]->makeSound();
		std::cout << animals[i]->getType() << std::endl;
		std::cout << "------------------------" << std::endl;
		delete animals[i];
	}

	return 0;
}