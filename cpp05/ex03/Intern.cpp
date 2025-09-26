/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:46:35 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 17:56:48 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

static AForm* createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
static AForm* createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
static AForm* createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    FormCreator creators[3] = {createShrubbery, createRobotomy, createPresidential};

    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern could not find the form: " << formName << std::endl;
    return NULL;
}
