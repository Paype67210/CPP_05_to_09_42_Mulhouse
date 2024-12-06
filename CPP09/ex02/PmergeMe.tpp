/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:56:31 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/25 11:34:42 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename Container>
void displayContainer(const Container &container, const std::string &name);

template <typename T, typename Container>
PmergeMe<T, Container>::PmergeMe(void) : _container() { };

template <typename T, typename Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe &src) { _container = src._container; };

template <typename T, typename Container >
PmergeMe<T, Container>::PmergeMe(const Container &container) : _container(container) { };

template <typename T, typename Container>
PmergeMe<T, Container> &PmergeMe<T, Container>::operator=(const PmergeMe &rhs)
{
	if (this != &rhs) {
		_container = rhs._container;
	}
	return *this;
};


template <typename T, typename Container>
PmergeMe<T, Container>::~PmergeMe(void) { };

template <typename T, typename Container>
const Container &PmergeMe<T, Container>::getContainer(void) const { return _container; };

template <typename T, typename Container>
void PmergeMe<T, Container>::setContainer(const Container &container) { _container = container; };

template <typename T, typename Container>
Container PmergeMe<T, Container>::sort(void) { return recursiveSort(_container); }

template <typename T, typename Container>
Container PmergeMe<T, Container>::recursiveSort(const Container& input) {
    if (input.size() <= 1)
        return input;

    std::vector<T> inputVec = containerToVector(input);
    std::vector<T> sortedLarger, sortedSmaller;
    T straggler = T(); // Gere l'element impair si necessaire
    bool hasStraggler = false;

    if (inputVec.size() % 2 != 0) {
        straggler = inputVec.back();
        inputVec.pop_back();
        hasStraggler = true;
    }
    
    for (size_t i = 0; i < inputVec.size(); i += 2) {
        if (inputVec[i] < inputVec[i + 1]) {
            sortedLarger.push_back(inputVec[i + 1]);
            sortedSmaller.push_back(inputVec[i]);
        } else {
            sortedLarger.push_back(inputVec[i]);
            sortedSmaller.push_back(inputVec[i + 1]);
        }
    }

    Container sortedLargerCont = vectorToContainer(sortedLarger);
    sortedLargerCont = recursiveSort(sortedLargerCont);
    std::vector<T> resultVec = containerToVector(sortedLargerCont);

    std::vector<size_t> insertionIndices = generateInsertionSequence(sortedSmaller.size());
    
    if (!sortedSmaller.empty()) {
        typename std::vector<T>::iterator insertPos = 
            std::lower_bound(resultVec.begin(), resultVec.end(), sortedSmaller[0]);
        resultVec.insert(insertPos, sortedSmaller[0]);
    }
    
    for (size_t i = 0; i < insertionIndices.size(); ++i) {
        size_t idx = insertionIndices[i];
        if (idx < sortedSmaller.size()) {
            T element = sortedSmaller[idx];
            typename std::vector<T>::iterator position = std::lower_bound(
                resultVec.begin(), 
                resultVec.end(), 
                element);
            resultVec.insert(position, element);
        }
    }
    // Gestion de l'element impair et du cas particulier ou celui ci est un doublon
    if (hasStraggler) {
        typename std::vector<T>::iterator it = std::find(resultVec.begin(), resultVec.end(), straggler);
        if (it == resultVec.end()) {
            typename std::vector<T>::iterator position = std::lower_bound(
                resultVec.begin(), 
                resultVec.end(), 
                straggler);
            resultVec.insert(position, straggler);
        }
    }
    return vectorToContainer(resultVec);
}

// Fonctions pour obtenir les termes de la suite de Jacobstahl jusqu'à une taille donnée

template <typename T, typename Container>
std::vector<size_t> PmergeMe<T, Container>::generateInsertionSequence(size_t n) {
    std::vector<size_t> sequence = jacobstahlSequence(n);
    std::vector<size_t> indices;
    std::vector<size_t> insertionSequence;
    
    for (size_t i = 0; i < sequence.size(); ++i)
        indices.push_back(sequence[i]);
    for (size_t i = 0; i < n; i++) {
        bool found = false;
        for (size_t j = 0; j < indices.size(); ++j) {
            if (indices[j] == i) {
                found = true;
                break;
            }
        }
        if (!found)
            insertionSequence.push_back(i);
    }
    return insertionSequence;
}

template <typename T, typename Container>
std::vector<size_t> PmergeMe<T, Container>::jacobstahlSequence(size_t limit) {
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);
    
    size_t i = 2;
    while (jacobsthal.back() < limit) {
        size_t next = jacobsthal[i-1] + 2 * jacobsthal[i-2];
        if (next > limit) break;
        jacobsthal.push_back(next);
        ++i;
    }
    return jacobsthal;
}

template <typename T, typename Container>
Container PmergeMe<T, Container>::vectorToContainer(const std::vector<T> &vec) { 
    return Container(vec.begin(), vec.end());
}

template <typename T, typename Container>
std::vector<T> PmergeMe<T, Container>::containerToVector(const Container &container) {
    return std::vector<T>(container.begin(), container.end());
}
