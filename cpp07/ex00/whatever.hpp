/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:23:17 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/08 16:32:03 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T> void swap (T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> T min(T a, T b) {
    return (a < b ? a : b);
}

template <typename T> T max(T a, T b) {
    return (a > b ? a : b);
}


#endif