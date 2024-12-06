/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:19:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/05 10:53:30 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void CheckArgs(char *arg)
{
	std::string expr = arg;
	size_t _count;
	std::string *split;
	double buffer;
	
	if (expr.empty())
		throw (std::invalid_argument("No expression provided"));
	for (std::string::iterator it = expr.begin(); it != expr.end(); it++)
	{
		if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '*' && *it != '/' && *it != ' ')
			throw (std::invalid_argument(expr + ": Invalid expression format"));
	}
	split = SplitStr(expr, ' ', _count);
	if (_count == 0) {
		delete [] split;
		throw (std::invalid_argument("No expression provided"));
	}
	for (size_t i = 0; i < _count; i++)
	{
		if (isdigit(split[i][0]))
		{
			buffer = strtod(split[i].c_str(), NULL);
			if (buffer > 9 || buffer < 0)
			{
				delete [] split;
				throw (std::invalid_argument("Value out of range"));
			}
		}
		else if (split[i] != "+" && split[i] != "-" && split[i] != "*" && split[i] != "/")
		{
			delete [] split;
			throw (std::invalid_argument("Invalid expression format"));
		}
		else if ((split[i][0] == '+' || split[i][0] == '-' || split[i][0] == '*' || split[i][0] == '/') && \
			split[i][1] != '\0')
		{
			delete [] split;
			throw (std::invalid_argument("Invalid expression format"));
		}
	}
	delete [] split;
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Invalid number of arguments" << DEFAULT << std::endl;
		return EXIT_FAILURE;
	}
	try
	{
		CheckArgs(argv[1]);
		RPN rpn(argv[1]);
		std::cout << GREEN << argv[1] << " = " << DEFAULT;
		rpn.getResult();
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << DEFAULT << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}