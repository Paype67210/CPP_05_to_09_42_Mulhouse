/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:22:40 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 12:08:00 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyFind.hpp"
#include <vector>
#include <list>
#include <deque>

void testVector()
{
	std::cout << CYAN << "   ----- Testing vector -----" << DEFAULT << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::cout << YELLOW << "Vector content: ";
	for (int i = 0; i < 5; i++)
		std::cout << "[" << vec[i] << "] ";
	std::cout << DEFAULT << std::endl;
	std::cout << CYAN << "Try to find value 3 and 42" << DEFAULT << std::endl;
	try
	{
		int it = easyFind(vec, 3);
		std::cout << GREEN << "Found value " << it << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		int it = easyFind(vec, 42);
		std::cout << GREEN << "Found value " << it << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
}

void	testList()
{
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(11);
	lst.push_back(12);
	lst.push_back(13);
	lst.push_back(14);
	
	std::cout << YELLOW << "Vector content: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << "[" << *it << "] ";
	std::cout << DEFAULT << std::endl;
	
	std::cout << CYAN << "Try to find value 13 and 42" << DEFAULT << std::endl;
	try
	{
		int it = easyFind(lst, 13);
		std::cout << GREEN << "Found value " << it << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		int it = easyFind(lst, 42);
		std::cout << GREEN << "Found value " << it << DEFAULT << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

void testDeque()
{
	std::cout << CYAN << " ----- Testing deque -----" << DEFAULT << std::endl;
    std::deque<int> deq;
    deq.push_back(41);
    deq.push_back(42);
    deq.push_back(43);
    deq.push_back(44);
    deq.push_back(45);

    std::cout << YELLOW << "Deque content: ";
    for (size_t i = 0; i < deq.size(); i++)
        std::cout << "[" << deq[i] << "] ";
    std::cout << DEFAULT << std::endl;

    std::cout << CYAN << "Try to find value 3 and 42" << DEFAULT << std::endl;
    try
    {
        int it = easyFind(deq, 3);
        std::cout << GREEN << "Found value " << it << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DEFAULT << std::endl;
    }
    try
    {
        int it = easyFind(deq, 42);
        std::cout << GREEN << "Found value " << it << DEFAULT << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DEFAULT << std::endl;
    }
}

int	main(void)
{
	testVector();
	testList();
	testDeque();

	return 0;	
}
