/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarUtils.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 08:51:44 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/23 16:00:16 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static int	IsInt(std::string input) {
	int	i = 0, num;

	if (input.length() == 0 || input.length() > 12)
		return 0;
	if (isdigit(input[0] - 48) && input[0] != '+' && input[0] != '-')
		return 0;
	for (size_t x = 1; x < input.length(); x++) {
		if (input[x] < '0' || input[x] > '9')
			return 0;
	}
	num = atoi(input.c_str());
	if (input[i] == '-') {
		if (num > 0)
			return 0;
		return 1;
	}
	if (num < 0)
		return 0;
	return 1;
}

static int	IsFloat(std::string input, size_t dot) {
	for (int i = dot - 1; i >= 0; i--) {
		if (isdigit(input[i] -48) && i != 0)
			return 0;
		if (isdigit(input[i] - 48) && i == 0 && input[i] != '+' && input[i] != '-')
			return 0; 
	}
	for (size_t i = dot + 1; i < input.length(); i++) {
		if ((input[i] < '0' || input[i] > '9') && input[i] != 'f')
			return 0;
		if (input[i] == 'f' && i != input.length() - 1)
			return 0;
	}
	return 1;
}

int whichType(const std::string &input) {
	size_t dot = input.find('.');
	size_t f = input.find('f');

	// Si il n'y a pas de '.'
	if (dot == std::string::npos) {
		// gestion des depassements
		if (input == "nan" || input == "nanf" || input == "+inf" || input == "+inff" || \
			input == "-inf" || input == "-inff")
			return 1;
		// gestion des imprimables
		if ((input.length() == 1 && input == "\t"))
			std::cerr << GREY << "fdxxghjk" << DEFAULT << std::endl;
		if ((input.length() == 1 && isprint(input[0])) || \
			(input.length() == 3 && input[0] == '\'' && input[2] == '\''))
			return 2;
		// gestion des int
		if (IsInt(input))
			return 3;
	}
	// gestion des floats
	if (f != std::string::npos && dot != std::string::npos) {
		if (IsFloat(input, dot))
			return 4;
	}
	// gestion des doubles
	else if (f == std::string::npos && dot != std::string::npos)
		return 5;
	return 0;
};

void	convertInt(const std::string input) {
	int num;

	num = atoi(input.c_str());
	if (num > 32 && num < 127)
		std::cout << YELLOW << "Char:\t'" \
			<< static_cast<char>(num) << "'" << DEFAULT << std::endl;
	else
		std::cout << RED << "Char:\tNon displayable character!" << DEFAULT << std::endl;
	std::cout << YELLOW << "Int:\t'" \
				<< static_cast<int>(num) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Float:\t'" \
				<< static_cast<float>(num) << "f'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Double:\t'" \
				<< static_cast<double>(num) << "'" << DEFAULT << std::endl;
};

void	convertFloat(const std::string input) {
	float num;

	num = strtof(input.c_str(), NULL);
	std::cout << YELLOW << "Char:\t'" \
				<< static_cast<char>(num) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << "Int:\t'" \
				<< static_cast<int>(num) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Float:\t'" \
				<< static_cast<float>(num) << "f'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Double:\t'" \
				<< static_cast<double>(num) << "'" << DEFAULT << std::endl;
};

void	convertDouble(const std::string input) {
	double num;

	num = strtod(input.c_str(), NULL);
	std::cout << YELLOW << "Char:\t'" \
				<< static_cast<char>(num) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << "Int:\t'" \
				<< static_cast<int>(num) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Float:\t'" \
				<< static_cast<float>(num) << "f'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Double:\t'" \
				<< static_cast<double>(num) << "'" << DEFAULT << std::endl;
};

void	convertChar(const std::string input) {
	char buffer;

	if (input[0] != '\'')
		buffer = input[0];
	else
		buffer = input[1];
	std::cout << YELLOW << "Char:\t'" \
				<< (buffer) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << "Int:\t'" \
				<< static_cast<int>(buffer) << "'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Float:\t'" \
				<< static_cast<float>(buffer) << "f'" << DEFAULT << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "Double:\t'" \
				<< static_cast<double>(buffer) << "'" << DEFAULT << std::endl;
};
