/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Awesome.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:58:14 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 00:19:59 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWESOME_HPP
# define AWESOME_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <cctype>
# include <cstdlib>
# include <sstream>

class Contact
{
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;
public:
	void	set_first_name(std::string first_name);
	void	set_last_name(std::string last_name);
	void	set_nickname(std::string nickname);
	void	set_phone_number(std::string phone_number);
	void	set_darkest_secret(std::string darkest_secret);
	std::string	get_first_name();
	std::string	get_last_name();
	std::string	get_nickname();
	std::string	get_phone_number();
	std::string	get_darkest_secret();
};

class PhoneBook
{
public:
	Contact contacts[8];
	int		contact_count;
	int		index;
	void	add_contact(PhoneBook& phonebook);
	void	display_contact();
	void	exit_phonebook();
};

std::string	get_input();
void		print_prompt();
void		check_command(std::string command, PhoneBook& phonebook);
int			fill(PhoneBook& phonebook);
int			check_empty(std::string str);
std::string	resize_word(std::string word);
void		print_contact(Contact contact, int index);
int			string_to_int(const std::string& str);
void		index_display(PhoneBook& phonebook, std::string index);



#endif