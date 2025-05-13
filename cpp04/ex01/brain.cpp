/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:55:44 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/13 16:08:49 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain(){
	for (int i = 0; i < 100; i++)
		ideas[i] = " new idea";
}

Brain::~Brain() {
	std::cout << "default destructor for Brain is called." << std::endl;
}

Brain& Brain::operator=(const Brain &other) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::Brain(const Brain& copy) {
	std::cout << "copy constructor for Brain is called." << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
}

std::string Brain::getIdeas(int index) const {
	if (index < 0 || index >= 100)
		return "Invalid index";
	return ideas[index];
}
