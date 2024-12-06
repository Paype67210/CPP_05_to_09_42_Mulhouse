/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:54:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/31 14:10:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "MutantStack.hpp"

// Constructeur par défaut
template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

// Constructeur par copie
template <typename T>
MutantStack<T>::MutantStack(const MutantStack& other) : std::stack<T>(other) {}

// Opérateur d'affectation
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other)
		std::stack<T>::operator=(other);
	return *this;
}

// Destructeur
template <typename T>
MutantStack<T>::~MutantStack() {}

// Itérateurs
template <typename T>
class MutantStack<T>::Iterator
{
	private:
		typename std::deque<T>::iterator _it;
	public:
		Iterator(typename std::deque<T>::iterator it) : _it(it) {}
		T& operator*() { return *_it; }
		Iterator& operator++() { _it++; return *this; }
		Iterator operator++(int) { Iterator tmp = *this; _it++; return tmp; }
		Iterator& operator--() { _it--; return *this; }
		Iterator operator--(int) { Iterator tmp = *this; _it--; return tmp; }
		bool operator==(const Iterator& rhs) { return _it == rhs._it; }
		bool operator!=(const Iterator& rhs) { return _it != rhs._it; }
		
};
	
template <typename T>
class MutantStack<T>::ReverseIterator
{
	private:
		typename std::deque<T>::reverse_iterator _it;
	public:
		ReverseIterator(typename std::deque<T>::reverse_iterator it) : _it(it) {}
		T& operator*() { return *_it; }
		ReverseIterator& operator++() { _it++; return *this; }
		ReverseIterator operator++(int) { ReverseIterator tmp = *this; _it++; return tmp; }
		ReverseIterator& operator--() { _it--; return *this; }
		ReverseIterator operator--(int) { ReverseIterator tmp = *this; _it--; return tmp; }
		bool operator==(const ReverseIterator& rhs) { return _it == rhs._it; }
		bool operator!=(const ReverseIterator& rhs) { return _it != rhs._it; }
};
	
// Itérateurs de début et de fin
template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::begin() {
	return Iterator(getContainer().begin());
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::end() {
	return Iterator(getContainer().end());
}

template <typename T>
const typename MutantStack<T>::Iterator MutantStack<T>::begin() const {
	return Iterator(getContainer().begin());
}

template <typename T>
const typename MutantStack<T>::Iterator MutantStack<T>::end() const {
	return Iterator(getContainer().end());
}

// Itérateurs inversés de début et de fin
template <typename T>
typename MutantStack<T>::ReverseIterator MutantStack<T>::rbegin() {
	return ReverseIterator(getContainer().rbegin());
}

template <typename T>
typename MutantStack<T>::ReverseIterator MutantStack<T>::rend() {
	return ReverseIterator(getContainer().rend());
}

template <typename T>
const typename MutantStack<T>::ReverseIterator MutantStack<T>::rbegin() const {
	return ReverseIterator(getContainer().rbegin());
}

template <typename T>
const typename MutantStack<T>::ReverseIterator MutantStack<T>::rend() const {
	return ReverseIterator(getContainer().rend());
}

