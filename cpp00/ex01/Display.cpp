/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:01:39 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 00:00:43 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Awesome.hpp"

std::string Contact::get_first_name()
{
	return (this->first_name);
}

std::string Contact::get_last_name()
{
	return (this->last_name);
}

std::string Contact::get_nickname()
{
	return (this->nickname);
}

std::string Contact::get_phone_number()
{
	return (this->phone_number);
}

void	print_prompt()
{
	std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	print_contact(Contact contact, int index)
{
	std::cout << "|" << std::setw(10) << index << "|"
			  << std::setw(10) << contact.get_first_name() << "|"
			  << std::setw(10) << contact.get_last_name() << "|"
			  << std::setw(10) << contact.get_nickname() << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	index_display(PhoneBook& phonebook, std::string index)
{
	int i = string_to_int(index);
	if (i < phonebook.contact_count)
	{
		print_prompt();
		print_contact(phonebook.contacts[i], i);
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void	PhoneBook::display_contact()
{
	print_prompt();
	for (int i = 0; i < contact_count; i++)
		print_contact(contacts[i], i);
}
