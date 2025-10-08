/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:23:17 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/08 18:11:07 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <cstddef>
#include <iostream>

template <typename T> class Array {
    private:
        T* elements;
        size_t length;

    public:
        Array() : elements(NULL), length(0) {};
        Array(unsigned int n) : elements(new T[n]()), length(n) {};
        ~Array() { delete[] elements; };
        Array(const Array& other) : elements(new T[other.length]()), length(other.length) {
            for (size_t i = 0; i < length; i++) {
                elements[i] = other.elements[i];
            }
        }
        Array& operator=(const Array& other) {
            if (this != &other) {
                T* tmp = new T[other.length]();
                for (size_t i = 0; i < other.length; i++)
                    tmp[i] = other.elements[i];
                delete[] elements;
                elements = tmp;
                length = other.length;
            }
            return *this;
        }
        T& operator[](size_t index) const {
            if (index >= length) {
                throw std::out_of_range("Index out of bounds");
            }
            return elements[index];
        }
        size_t size() const { return length; }
};


#endif