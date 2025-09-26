/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:54:22 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 18:20:31 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::~Form() {
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        throw GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        throw GradeTooLowException();
    }
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), 
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    } else {
        _isSigned = true;
        std::cout << bureaucrat.getName() << " signed " << _name << "." << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << f.getName()
       << ", form signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute()
       << ".";
    return os;
}
