/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:13:03 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 12:53:13 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "colors.hpp"

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span & operator=(Span const & rhs);

		void addNumber(unsigned int n);
		void addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
		void getNumbers();
		int shortestSpan();
		int longestSpan();

		class SpanFullException : public std::exception
		{
			public:
				SpanFullException();
				SpanFullException(SpanFullException const & src);
				~SpanFullException() throw();

				SpanFullException & operator=(SpanFullException const & rhs);

				const char * what() const throw();
		};

		class SpanNotEnoughNumbersException : public std::exception
		{
			public:
				SpanNotEnoughNumbersException();
				SpanNotEnoughNumbersException(SpanNotEnoughNumbersException const & src);
				~SpanNotEnoughNumbersException() throw();

				SpanNotEnoughNumbersException & operator=(SpanNotEnoughNumbersException const & rhs);

				const char * what() const throw();
		};

	private:
		Span();
		unsigned int _n;
		std::vector<unsigned int> _numbers;
};
