/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:12:16 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 16:41:31 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <fstream>

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
        
    public:
        AForm();
        virtual ~AForm();

        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

        class       GradeTooHighException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Grade is too high!";
                }
        };

        class       GradeTooLowException : public std::exception {  
            public:
                const char* what() const throw() {
                    return "Grade is too low!";
                }
        };

        class       FormNotSignedException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Form is not signed!";
                }
        };

        std::string getName() const { return _name; }
        bool        isSigned() const { return _isSigned; }

        int         getGradeToSign() const { return _gradeToSign; }
        int         getGradeToExecute() const { return _gradeToExecute; }

        virtual     void execute(const Bureaucrat& executor) const = 0;

        void        beSigned(const Bureaucrat& bureaucrat);
};

std::ostream& operator<<(std::ostream& os, const AForm& print);

#endif