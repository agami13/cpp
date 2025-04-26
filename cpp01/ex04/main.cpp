/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:57:21 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 20:48:36 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int argc, char *argv[]) {
	
	if (argc != 4) {
		std::cerr << "Error: Wrong number of parameters" << std::endl;
		return (1);
	}
	
	if (start_sed(argv)) {
		std::cerr << "Error: Failed to execute sed" << std::endl;
		return (1);
	}
	
	return (0);

}
