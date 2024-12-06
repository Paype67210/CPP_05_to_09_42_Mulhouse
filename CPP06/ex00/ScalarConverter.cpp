/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:51:44 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/24 14:07:10 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// Constructeur par défaut
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &src) {
	(void)src;
	// *this = src;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {};

void ScalarConverter::convert(const std::string input) {
	std::cout << YELLOW << std::endl << "Original string: " << input << DEFAULT;
	switch(whichType(input))
	{
		case 1: std::cout << RED << " Exception found" << std::endl \
			<< "char:\timpossible" << std::endl \
			<< "int:\timpossible" << std::endl \
			<< "float:\tnanf" << std::endl \
			<< "double:\tnan" << DEFAULT << std::endl;
			break;
		case 2: std::cout << GREEN << " (CHAR)" << DEFAULT << std::endl;
			convertChar(input);
			break;
		case 3: std::cout << GREEN << " (INT)" << DEFAULT << std::endl;
			convertInt(input);
			break;
		case 4: std::cout << GREEN << " (FLOAT)" << DEFAULT << std::endl;
			convertFloat(input);
			break;
		case 5: std::cout << GREEN << " (DOUBLE)" << DEFAULT << std::endl;
			convertDouble(input);
			break;
		default: std::cerr << RED << " Input is not INT / CHAR / DOUBLE / FLOAT" << DEFAULT << std::endl;
			break;
	}
}
