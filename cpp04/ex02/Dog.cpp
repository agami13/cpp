/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:49:52 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/12 18:51:15 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {

	std::cout << "Dog default constructor called" << std::endl;
	this->brain = new Brain();
	this->type = "Dog";

}

Dog::~Dog() {

	delete this->brain;
	this->brain = NULL;
	std::cout << "Dog destructor called" << std::endl;

}

Dog::Dog( const Dog& other ) : Animal(other) , brain(new Brain(*other.brain)) {

	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;

}

Dog& Dog::operator=( const Dog& other ) {

	std::cout << "Dog assignment operator called" << std::endl;

	if (this != &other) {
		Animal::operator=(other);
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}

	return *this;

}

void Dog::makeSound() const {
	std::cout << "Woof" << std::endl;
}
