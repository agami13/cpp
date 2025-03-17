/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:58:11 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 00:17:42 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

int main()
{
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