/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 19:57:52 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/03/17 23:09:06 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void	Sed::sed(Sed& sed, std::ifstream& File, std::ofstream& NewFile) {
	for (int i = 0; std::getline(File, sed._line); i++) {
		unsigned long pos = 0;
		while ((pos = sed._line.find(sed._s1, pos)) != std::string::npos) {
			for (unsigned long j = 0; j < sed._s1.length(); j++)
				sed._line[pos + j] = sed._s2[j];
		}
		NewFile << sed._line << std::endl;
		if (File.eof())
			break ;
	}
	File.close();
	NewFile.close();
}

int	start_sed(char **argv) {
	Sed sed;
	
	sed._filename = argv[1];
	sed._s1 = argv[2];
	sed._s2 = argv[3];
	sed._newfilename = sed._filename + ".replace";

	std::ifstream File(sed._filename.c_str());

	if (File.fail()) {
		std::cerr << "Error: File did not open" << std::endl;
		return (1);
	}

	std::ofstream NewFile(sed._newfilename.c_str());

	if (NewFile.fail()) {
		std::cerr << "Error: Failed to create new file" << std::endl;
		return (1);
	}

	Sed::sed(sed, File, NewFile);
	return (0);
}
