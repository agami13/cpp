/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:51:37 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/09/27 18:21:46 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    Data data;
    data.a = 42;
    data.b = 3.14f;
    data.c = 'X';

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized value: " << raw << std::endl;

    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &data) {
        std::cout << "Deserialize successful: pointers match!" << std::endl;
    } else {
        std::cout << "Deserialize failed: pointers do not match!" << std::endl;
    }

    std::cout << "Data values via deserialized pointer:" << std::endl;
    std::cout << "a = " << ptr->a << std::endl;
    std::cout << "b = " << ptr->b << std::endl;
    std::cout << "c = " << ptr->c << std::endl;

    return 0;
}
