/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:19:49 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/19 10:34:21 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(std::string expr)
{
	std::stack<int> _buffer;
	size_t _count;
	std::string *split = SplitStr(expr, ' ', _count);
	for (size_t i = 0; i < _count ; i++)
	{
		if (isdigit(split[i][0])) {
			_buffer.push(RPN::getValueStr(split[i]));
		}
		else if (_buffer.size() < 2)
			throw (std::invalid_argument("Not enough values to perform operation"));
		else if (split[i] == "+")
		{
			int a = _buffer.top();
			_buffer.pop();
			int b = _buffer.top();
			_buffer.pop();
			_buffer.push(a + b);
		}
		else if (split[i] == "-")
		{
			int a = _buffer.top();
			_buffer.pop();
			int b = _buffer.top();
			_buffer.pop();
			_buffer.push(b - a);
		}
		else if (split[i] == "*")
		{
			int a = _buffer.top();
			_buffer.pop();
			int b = _buffer.top();
			_buffer.pop();
			_buffer.push(a * b);
		}
		else if (split[i] == "/")
		{
			int a = _buffer.top();
			_buffer.pop();
			int b = _buffer.top();
			if (a == 0)
				throw (std::invalid_argument("Division by zero"));
			_buffer.pop();
			_buffer.push(b / a);
		}
	}
	this->_stack = _buffer;
	delete [] split;
	return;

}

RPN::RPN(RPN const &src)
{
	(void)src;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return *this;
}

void RPN::getResult(void) const
{
	if (this->_stack.size() != 1)
		throw (std::invalid_argument("Invalid expression"));
	std::cerr << GREEN << this->_stack.top() << DEFAULT << std::endl;
	return;
}

int RPN::getValueStr(std::string value) const
{
	double buffer = strtod(value.c_str(), NULL);
	if (buffer > 9 || buffer < 0)
		throw (std::invalid_argument(value + ": Value out of range"));
	return buffer;
}

std::string *SplitStr(std::string &line, char c, size_t &count)
{
	size_t start = 0;
	size_t end = line.find(c);
	std::string *split;
	
	count = 0;
	while (end != std::string::npos)
	{
		count++;
		start = end + 1;
		end = line.find(c, start);
	}
	count++;
	split = new std::string[count];
	start = 0;
	end = line.find(c);
	count = 0;
	while (end != std::string::npos)
	{
		split[count] = line.substr(start, end - start);
		start = end + 1;
		end = line.find(c, start);
		count++;
	}
	split[count] = line.substr(start);
	if (count == 0 && split[0].empty()) {
		delete [] split;
		throw (std::invalid_argument("No expression provided"));
	}
	count++;
	return split;
}
