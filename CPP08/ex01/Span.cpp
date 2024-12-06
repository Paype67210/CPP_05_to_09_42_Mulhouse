/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:17:37 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 12:58:41 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
		_n = rhs._n;
		_numbers = rhs._numbers;
	}
	return *this;
}

void Span::addNumber(unsigned int n)
{
	if (_numbers.size() >= _n)
		throw SpanFullException();
	_numbers.push_back(n);
}

void Span::getNumbers()
{
	for (std::vector<unsigned int>::iterator it = _numbers.begin(); it != _numbers.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void Span::addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _n)
		throw SpanFullException();
	_numbers.insert(_numbers.end(), begin, end);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw SpanNotEnoughNumbersException();
	std::sort(_numbers.begin(), _numbers.end());
	int min = _numbers[1] - _numbers[0];
	for (std::vector<unsigned int>::iterator it = _numbers.begin(); it != _numbers.end() - 1; it++)
	{
		if ((int)(*(it + 1) - *it) < min)
			min = *(it + 1) - *it;
	}
	return min;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw SpanNotEnoughNumbersException();
	std::sort(_numbers.begin(), _numbers.end());
	return _numbers[_numbers.size() - 1] - _numbers[0];
}

Span::SpanFullException::SpanFullException()
{
}

Span::SpanFullException::SpanFullException(SpanFullException const & src)
{
	*this = src;
}

Span::SpanFullException::~SpanFullException() throw()
{
}

Span::SpanFullException & Span::SpanFullException::operator=(SpanFullException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Span::SpanFullException::what() const throw()
{
	return "Span is full";
}

Span::SpanNotEnoughNumbersException::SpanNotEnoughNumbersException()
{
}

Span::SpanNotEnoughNumbersException::SpanNotEnoughNumbersException(SpanNotEnoughNumbersException const & src)
{
	*this = src;
}

Span::SpanNotEnoughNumbersException::~SpanNotEnoughNumbersException() throw()
{
}

Span::SpanNotEnoughNumbersException & Span::SpanNotEnoughNumbersException::operator=(SpanNotEnoughNumbersException const & rhs)
{
	(void)rhs;
	return *this;
}

const char * Span::SpanNotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to compute span";
}

