/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:03:36 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 17:00:05 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <stdexcept>

Bureaucrat::Bureaucrat() : name("Default Bureaucrat"), grade(150) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const {
    return name;
}

int Bureaucrat::getGrade() const {
    return grade;
}

void Bureaucrat::setGrade(int grade) {
    if (grade < 1) {
        throw GradeTooHighException();
        this->grade = 1; // Set to max grade
    } else if (grade > 150) {
        throw GradeTooLowException();
        this->grade = 150; // Set to min grade
    } else {
        this->grade = grade;
    }
}

void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    } else {
        --grade;
        std::cout << name << " incremented grade to " << grade << "." << std::endl;
    }
}

void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    } else {
        ++grade;
        std::cout << name << " decremented grade to " << grade << "." << std::endl;
    }
}

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
    } catch (const std::exception& e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat){

    os << "Bureaucrat Name: " << bureaucrat.getName() << ", Grade: " << bureaucrat.getGrade();
    return os;

}