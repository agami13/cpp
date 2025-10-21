/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:42:19 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/21 17:23:13 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe {
    private:
        std::vector<int> Vec;
        std::deque<int> Deq;
        void fordJohnsonSortVector(std::vector<int>& arr);
        void fordJohnsonSortDeque(std::deque<int>& arr);

        template<typename T>
            void binaryInsertion(T& mainChain, int element) {
                typename T::iterator left = mainChain.begin();
                typename T::iterator right = mainChain.end();
                while (left < right) {
                    typename T::iterator mid = left;
                    std::advance(mid, std::distance(left, right) / 2);
                    if (*mid < element)
                        left = ++mid;
                    else
                        right = mid;
                }
                mainChain.insert(left, element);
            }
        template<typename T>
            void DisplayContainer(const T& container, const std::string& label) const {
                std::cout << label << ": ";
                for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
                    std::cout << *it << " ";
                std::cout << std::endl;
            }
        template<typename T>
            bool isSorted(const T& container) const {
                if (container.empty())
                    return true;
                typename T::const_iterator it = container.begin();
                typename T::const_iterator next = it;
                ++next;
                for (; next != container.end(); ++it, ++next) {
                    if (*next < *it)
                        return false;
                }
                return true;
            }
        template<typename T>
            std::string measureSortTime(T& container, void (PmergeMe::*sortFunc)(T&), const std::string& label) {
                clock_t start = clock();
                (this->*sortFunc)(container);
                clock_t end = clock();
                double duration = double(end - start) / CLOCKS_PER_SEC * 1e6; // microseconds
                std::ostringstream oss;
                oss << "Time to process a range of " << container.size()
                    << " elements with " << label << " : "
                    << std::fixed << std::setprecision(3) << duration << " us";
                return oss.str();
            }

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();
         
        void parseInput(int argc, char** argv);
        void sortAndDisplay();
};

#endif