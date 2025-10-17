/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:42:11 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/17 22:36:03 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <stdexcept>

class RPN {
    private:
        std::stack<int> rpnStack;
        bool isOperator(char c) const;
        int applyOperator(char op, int a, int b) const;
        void clear();

    public:
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        int evaluate(const std::string& expression);
};


#endif