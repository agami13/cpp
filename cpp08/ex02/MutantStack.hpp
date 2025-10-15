/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:29:23 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/15 16:42:55 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <deque>
#include <iterator>
#include <algorithm>
#include <exception>

template<
    class T,
    class Container = std::deque<T>
> class MutantStack : public std::stack <T, Container> {
    public:
        typedef typename Container::iterator iterator;
        typedef typename Container::const_iterator const_iterator;
        typedef typename Container::reverse_iterator reverse_iterator;
        typedef typename Container::const_reverse_iterator const_reverse_iterator;
        
        MutantStack() : std::stack<T, Container>() {};
        MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {};
        MutantStack& operator=(const MutantStack& other) {
            if (this != &other) {
                std::stack<T, Container>::operator=(other);
            }
            return *this;
        }
        ~MutantStack() {};

        iterator begin() {
            return this->c.begin();
        }
        iterator end() {
            return this->c.end();
        }
        const_iterator begin() const {
            return this->c.begin();
        }
        const_iterator end() const {
            return this->c.end();
        }
        reverse_iterator rbegin() {
            return this->c.rbegin();
        }
        reverse_iterator rend() {
            return this->c.rend();
        }
        
};

#endif