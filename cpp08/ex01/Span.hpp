/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:16:36 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/15 16:22:49 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include <climits>

class Span {
    private:
        std::vector<int> numbers;
        unsigned int maxSize;
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span& other);
        Span& operator=(const Span& other);
        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
};

#endif