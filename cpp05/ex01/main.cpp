/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:04:04 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 15:25:11 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "\n=== Exercise 01: Form ===" << std::endl;
    try {
        Form f1("FormA", 50, 100);
        Form f2("FormB", 1, 1);

        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        Bureaucrat d("Dave", 75);
        Bureaucrat e("Eve", 40);

        std::cout << "\n-- Dave tries to sign FormA (needs 50) --" << std::endl;
        d.signForm(f1);

        std::cout << "\n-- Eve tries to sign FormA (needs 50) --" << std::endl;
        e.signForm(f1);

        std::cout << f1 << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    try {
        Form invalidForm("BadForm", 0, 151); // should throw
    }
    catch (std::exception &e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
