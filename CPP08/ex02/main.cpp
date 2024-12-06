/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:45:21 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/31 14:12:14 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main(void)
{
	std::cout << GREEN << "   ===== Tests for MutantStack =====" << DEFAULT << std::endl << std::endl;
	std::cout << CYAN << "Fullfeel a stack with {1, 2, 3, 4, 5}" << DEFAULT << std::endl;
	MutantStack<int> mstack;

	mstack.push(1);
	mstack.push(2);
	mstack.push(3);
	mstack.push(4);
	mstack.push(5);
	
	std::cout << YELLOW <<  "Top: " << mstack.top() << std::endl;
	std::cout << "Size: " << mstack.size() << std::endl << CYAN << std::endl;
	std::cout << "Suppression du dernier nombre avec Pop" << DEFAULT << std::endl;

	mstack.pop();

	std::cout << YELLOW << "New Size: " << mstack.size() << DEFAULT << std::endl << std::endl;
	std::cout << CYAN << "Adding {13, 42, 737, 0} with push" << DEFAULT << std::endl;

	mstack.push(13);
	mstack.push(42);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::Iterator it = mstack.begin();
	MutantStack<int>::Iterator ite = mstack.end();
	std::cout << CYAN << "Iterating through the stack" << YELLOW << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << DEFAULT << std::endl;
	
	std::cout << CYAN << "Copying the stack" << DEFAULT << std::endl;
	MutantStack<int> mstackCopy(mstack);
	MutantStack<int>::ReverseIterator itbis = mstackCopy.rbegin();
	MutantStack<int>::ReverseIterator itebis = mstackCopy.rend();
	std::cout << CYAN << "ReverseIterating through the copied stack" << YELLOW << std::endl;
	while (itebis != itbis)
	{
		std::cout << *itbis << std::endl;
		++itbis;
	}

	std::cout << std::endl << GREEN << "   ===== End of tests =====" << DEFAULT << std::endl;
	return 0;
}
