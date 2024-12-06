/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:14:10 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/23 16:00:49 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc == 2) 
		ScalarConverter::convert(argv[1]);
	else {
		// Realisation d'un ensemble de tests
		std::cout << CYAN << "Convertir 'G' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("G");
		
		std::cout << CYAN << "Convertir 'abc' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("abc");

		std::cout << CYAN << "Convertir '\t' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("\t");

		std::cout << CYAN << "Convertir '12342' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("12342");

		std::cout << CYAN << "Convertir '-42' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("-42");

		std::cout << CYAN << "Convertir 'INT_MAX + 1' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("2147483648");

		std::cout << CYAN << "Convertir '212.42' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("212.42");

		std::cout << CYAN << "Convertir '333.666f' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("333.666f");

		std::cout << CYAN << "Convertir '+inf' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("+inf");

		std::cout << CYAN << "Convertir 'nan' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("nan");

		std::cout << CYAN << "Convertir 'abc12.f' dans tous les types" << DEFAULT << std::endl;
		ScalarConverter::convert("abc12.f");
				
	}
	return 0;
	
}