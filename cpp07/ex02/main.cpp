/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:23:23 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/08 18:16:17 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main() {
    std::cout << "=== Test 1: Default constructor ===" << std::endl;
    Array<int> emptyArray;
    std::cout << "Empty array size: " << emptyArray.size() << std::endl;

    std::cout << "\n=== Test 2: Constructor with size ===" << std::endl;
    Array<int> intArray(5);
    std::cout << "intArray size: " << intArray.size() << std::endl;
    std::cout << "Elements before assignment: ";
    for (size_t i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    for (size_t i = 0; i < intArray.size(); ++i)
        intArray[i] = static_cast<int>(i * 10);

    std::cout << "Elements after assignment: ";
    for (size_t i = 0; i < intArray.size(); ++i)
        std::cout << intArray[i] << " ";
    std::cout << std::endl;

    std::cout << "\n=== Test 3: Copy constructor ===" << std::endl;
    Array<int> copyArray(intArray);
    std::cout << "copyArray elements: ";
    for (size_t i = 0; i < copyArray.size(); ++i)
        std::cout << copyArray[i] << " ";
    std::cout << std::endl;

    intArray[0] = 999;
    std::cout << "After modifying intArray[0] = 999:" << std::endl;
    std::cout << "intArray[0]: " << intArray[0] << std::endl;
    std::cout << "copyArray[0]: " << copyArray[0] << std::endl;

    std::cout << "\n=== Test 4: Assignment operator ===" << std::endl;
    Array<int> assignArray;
    assignArray = intArray;
    std::cout << "assignArray elements: ";
    for (size_t i = 0; i < assignArray.size(); ++i)
        std::cout << assignArray[i] << " ";
    std::cout << std::endl;

    intArray[1] = 888;
    std::cout << "After modifying intArray[1] = 888:" << std::endl;
    std::cout << "intArray[1]: " << intArray[1] << std::endl;
    std::cout << "assignArray[1]: " << assignArray[1] << std::endl;

    std::cout << "\n=== Test 5: Out-of-bounds access ===" << std::endl;
    try {
        std::cout << intArray[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: Array of strings ===" << std::endl;
    Array<std::string> strArray(3);
    strArray[0] = "Hello";
    strArray[1] = "World";
    strArray[2] = "42";
    for (size_t i = 0; i < strArray.size(); ++i)
        std::cout << strArray[i] << " ";
    std::cout << std::endl;

    return 0;
}
