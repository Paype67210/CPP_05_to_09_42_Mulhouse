/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:54:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 15:24:39 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>
#include "colors.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	private:
		typename std::deque<T>& getContainer() { return this->c; };
		const typename std::deque<T>& getContainer() const { return this->c; };
	
	public:
		// Constructeur par défaut & surchargé
		MutantStack();
		MutantStack(const MutantStack& other);
		
		// Opérateur d'affectation
		MutantStack& operator=(const MutantStack& other);
		
		// Destructeur
		~MutantStack();

		// Classes internes pour les itérateurs
		class Iterator;
		class ReverseIterator;

		// Itérateurs de début et de fin
		Iterator begin();
		Iterator end();
		const Iterator begin() const;
		const Iterator end() const;

		// Itérateurs inversés de début et de fin
		ReverseIterator rbegin();
		ReverseIterator rend();
		const ReverseIterator rbegin() const;
		const ReverseIterator rend() const;
};
	
#include "MutantStack.tpp"
