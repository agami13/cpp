/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:01:43 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 00:19:26 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

void	PhoneBook::exit_phonebook()
{
	std::cout << "Exiting phonebook" << std::endl;
	exit(0);
}

std::string	resize_word(std::string word)
{
	if (word.size() >= 10)
		return word.substr(0, 9) + ".";
	return (word);
}

int string_to_int(const std::string& str)
{
    int num = 0;
    std::stringstream ss(str);
    ss >> num;
    return num;
}

void	check_command(std::string command, PhoneBook &phonebook)
{
	if (command == "ADD")
		phonebook.add_contact(phonebook);
	else if (command == "SEARCH")
		phonebook.display_contact();
	else if (command == "EXIT")
		phonebook.exit_phonebook();
	else if (command >= "0" && command <= "7")
		index_display(phonebook, command);
	else
		std::cout << "Invalid command" << std::endl;
}

int	check_empty(std::string str)
{
	unsigned long	count;

	count = 0;
	if (str.empty())
	{
		std::cout << "Field cannot be empty" << std::endl;
		return (1);
	}
	else {
		for (size_t i = 0; i < str.size(); i++)
		{
			if (std::isspace(str[i]))
				count++;
		}
		if (count == str.size())
		{
			std::cout << "Field cannot be empty" << std::endl;
			return (1);
		}
	}
	return (0);
}

std::string	get_input()
{
	std::string tmp;

	if (!std::getline(std::cin, tmp) || std::cin.eof())
	{
		std::cout << std::endl << "Detected EOF, exiting phonebook" << std::endl;
		exit(0);
	}
	return (tmp);
}
