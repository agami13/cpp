/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:23:23 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/08 17:01:47 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>
#include "iter.hpp"

template<typename T> void printElement(const T& elem) {
    std::cout << elem << " ";
}

template<typename T> void increment(T& elem) {
    ++elem;
}

int main() {
    std::cout << "=== Testing with int array ===" << std::endl;
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intLen = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intLen, increment<int>);
    std::cout << "After increment: ";
    iter(intArray, intLen, printElement<int>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Testing with std::string array ===" << std::endl;
    std::string strArray[] = {"Hello", "World", "Templates", "Are", "Cool"};
    size_t strLen = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Strings: ";
    iter(strArray, strLen, printElement<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "=== Testing with double array ===" << std::endl;
    double dblArray[] = {1.1, 2.2, 3.3};
    size_t dblLen = sizeof(dblArray) / sizeof(dblArray[0]);

    std::cout << "Doubles: ";
    iter(dblArray, dblLen, printElement<double>);
    std::cout << std::endl;

    return 0;
}
