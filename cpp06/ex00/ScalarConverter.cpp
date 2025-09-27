/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:21:17 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/27 17:48:46 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cerrno>
#include <cstdlib>

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {
}

Type ScalarConverter::detectType(const std::string& literal) {
    if (isChar(literal)) return CHAR;
    if (isInt(literal)) return INT;
    if (isPseudoLiteral(literal)) return PSEUDO_LITERAL;
    if (isFloat(literal)) return FLOAT;
    if (isDouble(literal)) return DOUBLE;
    return INVALID;
}

bool ScalarConverter::isChar(const std::string& literal) {
    return (literal.length() == 1 && isprint(literal[0]) );
}

bool ScalarConverter::isInt(const std::string& literal) {
    size_t i = 0;
    if (literal[i] == '-' || literal[i] == '+') i++;
    if (i == literal.length()) return false;
    for (; i < literal.length(); i++) {
        if (!isdigit(literal[i])) return false;
    }
    return true;
}

bool ScalarConverter::isFloat(const std::string& literal) {
    if (literal.empty() || literal == "f" || literal[literal.length() - 1] != 'f') return false;

    const char* str = literal.c_str();
    char* end = NULL;
    errno = 0;
    std::strtod(str, &end);
    if (end == str) return false;
    size_t pos = end - str;
    if (pos != literal.length() - 1) return false;
    return true;
}

bool ScalarConverter::isDouble(const std::string& literal) {
    if (literal.empty()) return false;

    const char* str = literal.c_str();
    char* end = NULL;
    errno = 0;
    std::strtod(str, &end);
    if (end == str) return false;
    return end == str + literal.length();
}

bool ScalarConverter::isPseudoLiteral(const std::string& literal) {
    return isSpecialFloat(literal) || isSpecialDouble(literal);
}

bool ScalarConverter::isDisplayableChar(char c) {
    return (c >= 32 && c <= 126);
}

bool ScalarConverter::isSpecialFloat(const std::string& literal) {
    return (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff");
}

bool ScalarConverter::isSpecialDouble(const std::string& literal) {
    return (literal == "nan" || literal == "inf" || literal == "+inf" || literal == "-inf");
}

void ScalarConverter::printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (isDisplayableChar(c)) {
        std::cout << "'" << c << "'" << std::endl;
    } else {
        std::cout << "Non displayable" << std::endl;
    }
}

void ScalarConverter::printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    int i = static_cast<int>(value);
    std::cout << i << std::endl;
}

void ScalarConverter::printFloat(double value) {
    std::cout << "float: ";

    float f = static_cast<float>(value);

    if (f < -FLT_MAX || f > FLT_MAX) {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
    std::cout << "double: ";

    double d = static_cast<double>(value);
    
    if (d < -DBL_MAX || d > DBL_MAX) {
        std::cout << "impossible" << std::endl;
        return;
    }
    std::cout << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::printPseudoLiteral(const std::string& literal) {
    if (isSpecialFloat(literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nanf") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal == "+inff" || literal == "inff") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else if (literal == "-inff") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
    else if (isSpecialDouble(literal)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (literal == "nan") {
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        } else if (literal == "+inf" || literal == "inf") {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        } else if (literal == "-inf") {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
    }
}

void ScalarConverter::convert(const std::string& literal) {
    Type type = detectType(literal);
    switch (type) {
        case CHAR: {
            char c = literal[0];
            double value = static_cast<double>(c);
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case INT: {
            const char* str = literal.c_str();
            char* end = NULL;
            errno = 0;
            long li = std::strtol(str, &end, 10);
            double value = static_cast<double>(li);
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case FLOAT: {
            const char* str = literal.c_str();
            char* end = NULL;
            errno = 0;
            double tmp = std::strtod(str, &end);
            float f = static_cast<float>(tmp);
            double value = static_cast<double>(f);
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case DOUBLE: {
            const char* str = literal.c_str();
            char* end = NULL;
            errno = 0;
            double d = std::strtod(str, &end);
            double value = d;
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case PSEUDO_LITERAL:
            printPseudoLiteral(literal);
            break;
        case INVALID:
        default:
            std::cout << "Error: Invalid literal" << std::endl;
            break;
    }
}
