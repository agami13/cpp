/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 16:23:17 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/08 16:50:01 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename F> void iter(T* array, size_t length, F func) {
    for (size_t i = 0; i < length; i++) {
        func(array[i]);
    }
}


#endif