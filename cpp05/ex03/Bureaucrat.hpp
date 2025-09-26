/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:04:02 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/26 18:20:31 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <ostream>
#include <string>
#include <iostream>

class Bureaucrat {

    private:
        const       std::string name;
        int         grade;

    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
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
        void        signForm(class AForm& form);
        void        executeForm(const AForm& form) const;

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);


#endif