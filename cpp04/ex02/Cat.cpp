/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:50:06 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/12 18:51:00 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <new>

Cat::Cat() {

	std::cout << "Cat default constructor called" << std::endl;
	this->brain = new(std::nothrow) Brain();
	if (!this->brain) {
		std::cerr << "Memory allocation failed for Cat's brain" << std::endl;
		exit(1);
	}
	this->type = "Cat";

}

Cat::~Cat() {

	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
	this->brain = NULL;

}

Cat::Cat( const Cat& other ) : Animal(other), brain(new Brain(*other.brain)) {

	std::cout << "Cat copy constructor called" << std::endl;
	this->type = other.type;

}

Cat& Cat::operator=( const Cat& other ) {

	std::cout << "Cat assignment operator called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return *this;

}

void Cat::makeSound() const {
	std::cout << "Meow" << std::endl;
}