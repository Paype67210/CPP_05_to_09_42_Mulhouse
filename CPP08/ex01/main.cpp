/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:25:18 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 13:05:37 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	std::cout << CYAN << "Trying to add 6 numbers to a Span of size 5" << GREEN << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(5);
		sp.getNumbers();
		sp.addNumber(3);
		sp.getNumbers();
		sp.addNumber(17);
		sp.getNumbers();
		sp.addNumber(9);
		sp.getNumbers();
		sp.addNumber(11);
		sp.getNumbers();
		sp.addNumber(42);
		sp.getNumbers();
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		std::cout << DEFAULT << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << CYAN << "Trying to add only one number to a Span of size 5" << GREEN << std::endl;
	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(5);
		sp1.getNumbers();
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		std::cout << DEFAULT << "Shortest span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp1.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	std::cout << CYAN << "Trying to add DOWNSIZE & OVERSIZE numbers to a Span of size 5" << GREEN << std::endl;
	Span sp2 = Span(5);
	try
	{
		sp2.addNumber(2147483648);
		sp2.getNumbers();
		sp2.addNumber(-1);
		sp2.getNumbers();
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		std::cout << DEFAULT << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	std::cout << CYAN << "Trying to add 10 000 numbers to a Span" << GREEN << std::endl;
	Span sp3 = Span(10000);
	try
	{
		std::vector<unsigned int> v(10000, 42);
		sp3.addNumber(v.begin(), v.end());
		sp3.getNumbers();
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		std::cout << DEFAULT << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}	
	return 0;
}
