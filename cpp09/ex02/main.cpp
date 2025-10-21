/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:42:14 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/20 20:56:06 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char**argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integers...>" << std::endl;
        return 1;
    }
    PmergeMe sorter;
    try {
        sorter.parseInput(argc - 1, argv + 1);
        sorter.sortAndDisplay();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}