/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:58:11 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 11:15:35 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
	
	PhoneBook phonebook;
	std::string command;

	phonebook.contact_count = 0;
	phonebook.index = 0;
	while (1)
	{
		std::cout << "Please enter a command: ";
		command = get_input();
		check_command(command, phonebook);
	}
	return (0);
}