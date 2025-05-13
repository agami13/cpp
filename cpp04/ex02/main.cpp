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

    // Memory leak test
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    delete j; // should not create a leak
    delete i;

    // Array of animals
    Animal* animals[6];
    for (int i = 0; i < 3; i++)
        animals[i] = new Dog();
    for (int i = 3; i < 6; i++)
        animals[i] = new Cat();

    std::cout << "------------------------" << std::endl;

    // Copy constructor test
    std::cout << "Testing Copy Constructor:" << std::endl;
    Cat originalCat;
    Cat copiedCat(originalCat); // Copy constructor
    std::cout << "Original Cat Type: " << originalCat.getType() << std::endl;
    std::cout << "Copied Cat Type: " << copiedCat.getType() << std::endl;

    std::cout << "------------------------" << std::endl;

    // Copy assignment operator test
    std::cout << "Testing Copy Assignment Operator:" << std::endl;
    Dog originalDog;
    Dog assignedDog;
    assignedDog = originalDog; // Copy assignment
    std::cout << "Original Dog Type: " << originalDog.getType() << std::endl;
    std::cout << "Assigned Dog Type: " << assignedDog.getType() << std::endl;

    std::cout << "------------------------" << std::endl;

    // Test polymorphism and memory cleanup
    for (int i = 0; i < 6; i++) {
        animals[i]->makeSound();
        std::cout << animals[i]->getType() << std::endl;
        delete animals[i];
    }

    std::cout << "------------------------" << std::endl;

    // Deep copy test
    std::cout << "Testing Deep Copy:" << std::endl;
    Cat* cat1 = new Cat();
    Cat* cat2 = new Cat(*cat1); // Deep copy using copy constructor
    delete cat1; // Ensure cat2 is independent
    std::cout << "Cat2 Type after deleting Cat1: " << cat2->getType() << std::endl;
    delete cat2;

    std::cout << "------------------------" << std::endl;

    return 0;

}