/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:42:09 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/21 17:28:15 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(const RPN& other) : rpnStack(other.rpnStack) {
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other)
        rpnStack = other.rpnStack;
    return *this;
}

RPN::~RPN() {
}

void RPN::clear() {
    while (!rpnStack.empty()) rpnStack.pop();
}

bool RPN::isOperator(char c) const {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::applyOperator(char op, int a, int b) const {
    switch (op) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return a * b;
        case '/' : if (b != 0) return a / b;
                   throw std::invalid_argument("Division by zero");
        default  : throw std::invalid_argument("Invalid operator");
    }
    return 0; // Should never reach here
}

int RPN::evaluate(const std::string& expression) {
    clear();
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (token.size() == 1 && std::isdigit(token[0])) {
            int value = token[0] - '0';
            rpnStack.push(value);
        }
        else if (token.size() == 1 && isOperator(token[0])) {
            if (rpnStack.size() < 2)
                throw std::invalid_argument("Insufficient values in expression");
            int b = rpnStack.top(); rpnStack.pop();
            int a = rpnStack.top(); rpnStack.pop();
            int result = applyOperator(token[0], a, b);
            rpnStack.push(result);
        }
        else
            throw std::invalid_argument("Invalid token: " + token);
    }

    if (rpnStack.size() != 1)
        throw std::invalid_argument("The user input has too many or too few values");

    return rpnStack.top();
}