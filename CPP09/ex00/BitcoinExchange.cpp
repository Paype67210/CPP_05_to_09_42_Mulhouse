/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:27:24 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/04 09:55:09 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Btc::Btc(void)
{
	try
	{
		FillTableExchange();
	}
	catch(const std::exception& e)
	{
		std::string error = e.what();
		throw (std::runtime_error("Invalid data table: " + error));
	}
}

Btc::Btc(Btc const &src)
{
	*this = src;
}

Btc::~Btc(void) {}

Btc &Btc::operator=(Btc const &rhs)
{
	(void)rhs;
	return *this;
}

double Btc::getExchangedValue(time_t date) const
{
	std::map<time_t, double>::const_iterator it = _exchangeMap.find(date);
	if (date < _exchangeMap.begin()->first)
		throw (std::invalid_argument("No exchange rate found for this date"));
	for (int i = 0; it == _exchangeMap.end(); i++)
	{
		time_t newDate = date - i * 86400;
		it = _exchangeMap.find(newDate);
	}
	return it->second;
}

void Btc::FillTableExchange(void) {
	std::string datafile = "data/data.csv";
	struct stat buffer;
	
	if (stat(datafile.c_str(), &buffer) != 0)
		throw (std::runtime_error(datafile + ": File not found"));
	if ((buffer.st_mode & S_IFREG) == 0)
		throw (std::runtime_error(datafile + ": Is a Directory"));
	if ((buffer.st_mode & S_IXUSR) != 0)
		throw (std::runtime_error(datafile + ": Is an Executable"));
	std::fstream fd;
	fd.open(datafile.c_str(), std::fstream::in);
	if (!fd.is_open())
		throw (std::runtime_error(datafile + ": Open failed"));
	char line[100];
	fd.getline(line, 100);
	if (std::string(line) == "date,exchange_rate")
		fd.getline(line, 100);
	while (!fd.eof()) {
		if (!fd.eof() && line[0]) {
			FillTableExchangeLine(line);
		}
		fd.getline(line, 100);
	}
	std::cerr << GREY << "\tData.csv has been treated!" << std::endl;
}

void Btc::FillTableExchangeLine(std::string line) {
	struct tm tm;
	memset(&tm, 0, sizeof(struct tm));
	time_t date;
	std::string format = "%F"; // means %Y-%0m-%0d;
	std::string *split = SplitStr(line, ',');
	
	if (!strptime(split[0].c_str(), format.c_str(), &tm))
		throw (std::invalid_argument(split[0] + ": Invalid date format"));
	date = mktime(&tm);
	CheckValue(split[1]);
	double value = Btc::getValueStr(split[1]);
	
	AddTableExchangeLine(date, value);
	delete [] split; 
	
}

void Btc::AddTableExchangeLine(time_t date, double value) {
	std::map<time_t, double>::iterator it = _exchangeMap.find(date);
	if (it != _exchangeMap.end())
		it->second = value;
	else
		_exchangeMap.insert(std::pair<time_t, double>(date, value));
}

double Btc::getValueStr(std::string value) const {
	double buffer = std::strtod(value.c_str(), NULL);
	if (buffer < 0)
		throw (std::invalid_argument(value + ": Not a positive value"));
	else if (buffer > std::numeric_limits<int>::max())
		throw (std::invalid_argument(value + ": Value too high"));
	return buffer;
}
