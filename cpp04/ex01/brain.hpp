/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:55:47 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/05/13 16:02:15 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
	private:
		std::string ideas[100];
	
		public:
		Brain();
		Brain& operator=(const Brain &other);
		Brain(const Brain& copy);
		~Brain();
		std::string getIdeas(int index) const; 
};

#endif