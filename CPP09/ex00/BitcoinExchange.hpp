/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:59:29 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/04 09:51:16 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <map>
#include <sys/stat.h>
#include "colors.hpp"

class Btc
{
	public:
		// Constructor
		Btc(void);
		Btc(Btc const &src);

		// Destructor
		~Btc(void);

		// Operator
		Btc &operator=(Btc const &rhs);
		double getValueStr(std::string value) const;
		double getExchangedValue(time_t date) const;

	private:
		std::map<time_t, double> _exchangeMap;

		void FillTableExchange(void);
		void FillTableExchangeLine(std::string line);
		void AddTableExchangeLine(time_t date, double value);
};

time_t CheckDate(std::string date);
void CheckValue(std::string value);
std::string *SplitStr(std::string line, char c);
bool IsEmpty(std::string str);
