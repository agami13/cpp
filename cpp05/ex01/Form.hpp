/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 14:54:25 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 16:30:48 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        
    public:
        Form();
        ~Form();

        Form(const std::string& name, int gradeToSign, int gradeToExecute);
        Form(const Form& other);
        Form& operator=(const Form& other);

        class   GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too high!";
                }
        };

        class   GradeTooLowException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too low!";
                }
        };


        std::string getName() const { return _name; }
        bool        isSigned() const { return _isSigned; }

        int         getGradeToSign() const { return _gradeToSign; }
        int         getGradeToExecute() const { return _gradeToExecute; }

        void        beSigned(const Bureaucrat& bureaucrat);
        
};

std::ostream& operator<<(std::ostream& os, const Form& print);

#endif