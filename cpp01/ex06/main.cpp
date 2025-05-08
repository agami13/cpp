/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 23:10:49 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/29 20:55:17 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv) {
	
	if (argc != 2) {
		std::cerr << "Usage: ./harl <complain>" << std::endl;
		return 1;
	}
	
	Harl harl;
	harl.complain(argv[1]);
	return 0;

}
