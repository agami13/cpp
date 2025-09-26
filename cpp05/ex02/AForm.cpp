/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:11:53 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 16:51:17 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::~AForm() {
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1) {
        GradeTooHighException();
    } else if (gradeToSign > 150 || gradeToExecute > 150) {
        GradeTooLowException();
    }
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), 
    _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        _isSigned = other._isSigned;
    }
    return *this;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign) {
        throw GradeTooLowException();
    } else {
        _isSigned = true;
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << f.getName()
       << ", form signed: " << (f.isSigned() ? "yes" : "no")
       << ", grade to sign: " << f.getGradeToSign()
       << ", grade to execute: " << f.getGradeToExecute()
       << ".";
    return os;
}

void AForm::execute(const Bureaucrat& executor) const {
    if (!_isSigned) {
        throw FormNotSignedException();
    }
    if (executor.getGrade() > _gradeToExecute) {
        throw GradeTooLowException();
    }
    // The actual execution logic should be implemented in derived classes
}