/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:42:03 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 18:55:58 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
    Intern someRandomIntern;

    std::cout << "=== Valid forms ===" << std::endl;
    try {
        AForm* form1 = someRandomIntern.makeForm("shrubbery creation", "Home");
        AForm* form2 = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* form3 = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

        // Print addresses to verify forms are created
        std::cout << "Form1: " << form1 << std::endl;
        std::cout << "Form2: " << form2 << std::endl;
        std::cout << "Form3: " << form3 << std::endl;

        // Cleanup
        delete form1;
        delete form2;
        delete form3;
    } catch (std::exception &e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Invalid form ===" << std::endl;
    try {
        AForm* invalidForm = someRandomIntern.makeForm("nonexistent form", "Target");
        if (!invalidForm) {
            std::cout << "No form returned, as expected." << std::endl;
        } else {
            delete invalidForm; // just in case
        }
    } catch (std::exception &e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

