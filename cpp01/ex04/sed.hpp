/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:57:54 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/04/26 20:49:18 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
#define SED_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstddef>

class Sed {
	
	public:
		std::string _filename;
		std::string _newfilename;
		std::string _s1;
		std::string _s2;
		std::string _line;
		static void sed(Sed& sed, std::ifstream& File, std::ofstream& NewFile);
	
};

int		start_sed(char *argv[]);

#endif