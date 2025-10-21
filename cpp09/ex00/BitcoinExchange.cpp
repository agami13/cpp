/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:41:03 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/21 17:30:02 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
    loadData(dataFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    dataMap = other.dataMap;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        dataMap = other.dataMap;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static std::string trim(const std::string& str) {
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
        ++start;

    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
        --end;

    return str.substr(start, end - start);
}

void BitcoinExchange::loadData(const std::string& dataFile) {
    std::ifstream file(dataFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open data file: " + dataFile);
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date;
        double value;
        if (std::getline(ss, date, ',') && ss >> value)
            dataMap[trim(date)] = value;
    }
    file.close();
    std::cout << "Data loaded successfully from " << dataFile << std::endl;
    std::cout << "Total records loaded: " << dataMap.size() << std::endl;
}

double BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, double>::const_iterator it = dataMap.find(date);
    if (it != dataMap.end())
        return it->second;
    else
        throw std::runtime_error("Date not found: " + date);
}

bool BitcoinExchange::isValidValue(const std::string& valueStr, double& value) const {
    std::string trimmedValue = trim(valueStr);
    if (trimmedValue.empty()) return false;
    try {
        std::stringstream ss(trimmedValue);
        ss >> value;
        if (ss.fail() || ss.peek() != std::stringstream::traits_type::eof() || value < 0 || value > 1000)
            return false;
    } catch (...) {
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    std::string trimmedDate = trim(date);
    if (trimmedDate.empty()) return false;
    if (trimmedDate.length() != 10 || trimmedDate[4] != '-' || trimmedDate[7] != '-')
        return false;
    int month = std::atoi(trimmedDate.substr(5, 2).c_str());
    int day = std::atoi(trimmedDate.substr(8, 2).c_str());
    if (month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

double BitcoinExchange::findClosestRate(const std::string& date) const {
    if (date.empty()) throw std::runtime_error("Invalid date format: " + date);
    std::map<std::string, double>::const_iterator it = dataMap.lower_bound(date);
    if (it != dataMap.end() && it->first == date)
        return it->second;
    if (it == dataMap.begin())
        throw std::runtime_error("No earlier date available for: " + date);
    --it;
    return it->second;
}


void BitcoinExchange::processInputFile(const std::string& inputFile) {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open input file: " + inputFile);
    std::string line;
    std::getline(file, line);
    while(std::getline(file, line)) {
        std::ostringstream output;
        std::istringstream ss(line);
        std::string date, valueStr;
        if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
            double value;
            try {
                if (!isValidDate(date))
                    output << "Error: Invalid date => " << date << std::endl;
                else if (!isValidValue(valueStr, value))
                    output << "Error: Invalid value => " << valueStr << std::endl;
                else {
                    double rate = findClosestRate(trim(date));
                    output << date << " => " << value << " = " << (value * rate) << std::endl;
                }
            } catch (const std::exception& e) {
                output << "Error: " << e.what() << std::endl;
            }
        } else
            output << "Error: Malformed line => " << line << std::endl;
        std::cout << output.str();
    }
    file.close();
}
