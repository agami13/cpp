/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:42:03 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 16:44:49 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    try {
        Bureaucrat bob("Bob", 140);
        Bureaucrat alice("Alice", 1);
        Bureaucrat john("John", 50);

        ShrubberyCreationForm shrub("Home");
        RobotomyRequestForm robo("Marvin");
        PresidentialPardonForm pardon("Arthur Dent");

        std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
        try {
            bob.signForm(shrub); // too low
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        john.signForm(shrub); // success
        try {
            bob.executeForm(shrub); // too low
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        alice.executeForm(shrub); // success

        std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
        try {
            bob.signForm(robo); // too low
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        alice.signForm(robo); // success
        try {
            john.executeForm(robo); // too low
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        alice.executeForm(robo); // success, random drilling

        std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
        try {
            john.signForm(pardon); // too low
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        alice.signForm(pardon); // success
        try {
            john.executeForm(pardon); // too low
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        alice.executeForm(pardon); // success

    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}

