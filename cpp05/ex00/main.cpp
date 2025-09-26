/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:04:04 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 15:25:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    std::cout << "=== Exercise 00: Bureaucrat ===" << std::endl;
    try {
        Bureaucrat a("Alice", 1);
        Bureaucrat b("Bob", 150);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << "\n-- Testing grade increment/decrement --" << std::endl;
        b.decrementGrade(); // should throw
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat c("Charlie", 2);
        std::cout << c << std::endl;
        c.incrementGrade(); // should succeed (grade 2 -> 1)
        std::cout << c << std::endl;
        c.incrementGrade(); // should throw (already at grade 1)
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidHigh("FailHigh", 0); // should throw
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Bureaucrat invalidLow("FailLow", 200); // should throw
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}