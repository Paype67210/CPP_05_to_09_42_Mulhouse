/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:07:11 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/23 15:36:51 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "colors.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter &operator=(ScalarConverter const &rhs);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		
	public:
		
		static void	convert(std::string input);
		
};

int		whichType(const std::string &input);
void	convertInt(const std::string input);
void	convertFloat(const std::string input);
void	convertDouble(const std::string input);
void	convertChar(const std::string input);
