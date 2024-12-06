/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:56:36 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/25 11:20:49 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <deque>
#include <climits>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <set>
#include <stdexcept>
#include <utility>
#include "colors.hpp"

template <typename T, typename Container>
class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(const PmergeMe &src);
		PmergeMe(const Container &container);
		PmergeMe &operator=(const PmergeMe &rhs);
		~PmergeMe(void);
		
		// Getters
		const Container &getContainer(void) const;

		// Setters
		void setContainer(const Container &container);
		
		// Tri selon Ford-Johnson et Jacobstahl
		Container sort(void);
	
	private:
		Container _container;

		std::vector<size_t> jacobstahlSequence(size_t limit);
		Container recursiveSort(const Container &input);
		std::vector<size_t> generateInsertionSequence(size_t n);
		
		Container vectorToContainer(const std::vector<T> &vec);
		std::vector<T> containerToVector(const Container &container);

};

#include "PmergeMe.tpp"

