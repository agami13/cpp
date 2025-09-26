/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:04:02 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 16:30:25 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <iostream>

class Form;

class Bureaucrat {

    private:
        const       std::string name;
        int         grade;

    public:
        Bureaucrat();
        ~Bureaucrat();
        
        Bureaucrat(const std::string &name, int grade) : name(name) {
        setGrade(grade);
        }
        Bureaucrat& operator=(const Bureaucrat& other); 
        
        std::string getName() const;
        int         getGrade() const;
        
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

        void        setGrade(int grade);
        void        incrementGrade();
        void        decrementGrade();
        void        signForm(Form& form);

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif