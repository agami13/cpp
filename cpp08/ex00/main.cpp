/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:13:31 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/15 16:15:27 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {
    int find = 9;
    std::vector<int> vec;
    for (int i = 0; i < 10; i++)
        vec.push_back(i);
    try {
        std::vector<int>::iterator it = easyfind(vec, find);
        std::cout << "Found in vector: " << *it << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}