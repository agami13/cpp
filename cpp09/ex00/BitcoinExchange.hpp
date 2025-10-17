/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:41:06 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/17 20:44:42 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <stdexcept>
#include <cstdlib>

class BitcoinExchange {
    private:
        std::map<std::string, double> dataMap;
        void loadData(const std::string& dataFile);
        bool isValidDate(const std::string& date) const;
        bool isValidValue(const std::string& valueStr, double& value) const;
        double findClosestRate(const std::string& date) const;

    public:
        BitcoinExchange(const std::string& dataFile);
        void processInputFile(const std::string& inputFile);
        double getExchangeRate(const std::string& date) const;
        ~BitcoinExchange();
};

#endif