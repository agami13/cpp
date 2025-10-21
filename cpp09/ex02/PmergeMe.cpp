/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouaoud <ybouaoud@1337.student.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:42:16 by ybouaoud          #+#    #+#             */
/*   Updated: 2025/10/21 13:37:15 by ybouaoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) {
    Vec = other.Vec;
    Deq = other.Deq;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        Vec = other.Vec;
        Deq = other.Deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        std::istringstream iss(argv[i]);
        int num;
        if (!(iss >> num) || num < 0)
            throw std::runtime_error("Error");
        if (Vec.size() > 0 && std::find(Vec.begin(), Vec.end(), num) != Vec.end())
            throw std::runtime_error("Error: Duplicates are not allowed");
        Vec.push_back(num);
        Deq.push_back(num);
    }
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& arr) {
    // Implementation of Ford-Johnson sorting algorithm for vector
    if (arr.size() <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    std::vector<int> A, B;
    std::vector<int> mainChain;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    for (size_t i = 0; i < pairs.size(); i++) {
        A.push_back(pairs[i].second);
        B.push_back(pairs[i].first);
    }
    if (arr.size() % 2 != 0)
        B.push_back(arr.back());
    
    fordJohnsonSortVector(A);
    mainChain = A;
    
    // std::vector<size_t> jacobSeq = jacobSthalForm<std::vector<size_t> >(B.size());
    // size_t insrt = 1;
    // for (size_t k = 0; k < jacobSeq.size(); k++) {
    //     size_t limit = std::min(insrt + jacobSeq[k], B.size());
    //     for (size_t J = limit; J > insrt; --J)
    //         binaryInsertion(mainChain, B[J - 1]);
    //     insrt = limit;
    // }
    
    // for (size_t i = insrt; i < B.size(); ++i)
    //     binaryInsertion(mainChain, B[i]);
    for (size_t idx = B.size(); idx-- > 0; ) {
        binaryInsertion(mainChain, B[idx]);
    }
    arr = mainChain;
}

void PmergeMe::fordJohnsonSortDeque(std::deque<int>& arr) {
    // Implementation of Ford-Johnson sorting algorithm for deque
    if (arr.size() <= 1)
        return;
    std::deque<std::pair<int, int> > pairs;
    std::deque<int> A, B;
    std::deque<int> mainChain;
    
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1])
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        else
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
    }

    for (size_t i = 0; i < pairs.size(); i++) {
        A.push_back(pairs[i].second);
        B.push_back(pairs[i].first);
    }
    if (arr.size() % 2 != 0)
        B.push_back(arr.back());
    
    fordJohnsonSortDeque(A);
    mainChain = A;

    // std::deque<size_t> jacobSeq = jacobSthalForm<std::deque<size_t> >(B.size());
    // size_t insrt = 1;
    // for (size_t k = 0; k < jacobSeq.size(); k++) {
    //     size_t limit = std::min(insrt + jacobSeq[k], B.size());
    //     for (size_t J = limit; J > insrt; --J)
    //         binaryInsertion(mainChain, B[J - 1]);
    //     insrt = limit;
    // }
    // for (size_t i = insrt; i < B.size(); ++i)
    //     binaryInsertion(mainChain, B[i]);
    for (size_t idx = B.size(); idx-- > 0; ) {
        binaryInsertion(mainChain, B[idx]);
    }
    arr = mainChain;
}

void PmergeMe::sortAndDisplay() {
    DisplayContainer(Vec, "Before: ");
    measureSortTime(Vec, &PmergeMe::fordJohnsonSortVector, "std::vector");
    if (!isSorted(Vec))
        throw std::runtime_error("STL Container is not sorted correctly");
    measureSortTime(Deq, &PmergeMe::fordJohnsonSortDeque, "std::deque");
    DisplayContainer(Deq, "After: ");
    if (!isSorted(Deq))
        throw std::runtime_error("STL Container is not sorted correctly");
}