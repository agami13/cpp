/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:41:06 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/20 19:54:53 by ybouaoud         ###   ########.fr       */
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
        BitcoinExchange(const BitcoinExchange& other);
        BitcoinExchange& operator=(const BitcoinExchange& other);
        void processInputFile(const std::string& inputFile);
        double getExchangeRate(const std::string& date) const;
        ~BitcoinExchange();
};

#endif