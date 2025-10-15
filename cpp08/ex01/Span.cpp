/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:16:38 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/15 16:28:45 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::~Span() {}

Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw std::runtime_error("Cannot add more numbers, span is full");
    }
    numbers.push_back(number);
}

int Span::shortestSpan() {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = INT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() {
    if (numbers.size() < 2) {
        throw std::runtime_error("Not enough numbers to find a span");
    }
    int minNumber = *std::min_element(numbers.begin(), numbers.end());
    int maxNumber = *std::max_element(numbers.begin(), numbers.end());
    return maxNumber - minNumber;
}
