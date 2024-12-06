/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 09:56:40 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/19 10:28:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool IsEmpty(std::string str)
{
	if (str.empty())
		return true;
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
	{
		if (!isblank(*it))
			return false;
	}
	return true;
}

bool CanEvaluate(char *line)
{
	std::string GoodStr(line);
	if (IsEmpty(line) || GoodStr == "date | value")
		return false;
	return true;
}

void	CheckArgs(int argc)
{
	if (argc != 2)
		throw std::invalid_argument("Invalid number of arguments: Usage ./btc [file.txt]");
}

std::fstream	*OpenFile(char *filename)
{
	std::string		file = filename;
	struct stat		buffer;
	
	if (stat(filename, &buffer) != 0)
		throw std::invalid_argument(file + " does not exist");
	// if ((file.rfind(".txt") == std::string::npos))
	// 	throw std::invalid_argument("Invalid file extension: Usage ./btc [file.txt]");
	if ((buffer.st_mode & S_IFREG) == 0)
		throw std::invalid_argument(file + " is a Directory");
	if ((buffer.st_mode & S_IXUSR) != 0)
		throw std::invalid_argument(file + " is an executable file");
	std::fstream *fd = new std::fstream();
	fd->open(filename, std::fstream::in);
	if (!fd->is_open())
		throw std::invalid_argument("Could not open " + file);
	return fd;
}

std::string *SplitStr(std::string line, char c)
{
	std::string *split = new std::string[2];
	size_t pos = line.find(c, 0);
	if (pos == std::string::npos) {
		delete [] (split);
		throw std::invalid_argument(line + ": Invalid line format");
	}
	split[0] = line.substr(0, pos);
	split[1] = line.substr(pos + 1, std::string::npos);
	return split;
}

void Evaluation(Btc &btc, std::fstream &fd)
{
	int i = 0;
	while (!fd.eof())
	{
		char line[100];
		fd.getline(line, 100);
		if (fd.eof() || !CanEvaluate(line)) {
			i++;
			continue;	
		}
		std::string *split = NULL;
		try
		{
			split = SplitStr(line, '|');
			time_t InputDate = CheckDate(split[0]);
			// Traitement du split
			char FinalDate[13];
			struct tm *tm = localtime(&InputDate);
			strftime(FinalDate, 13, "%Y-%m-%d", tm);
			CheckValue(split[1]);
			double FinalValue = btc.getValueStr(split[1]);
			if (FinalValue > 1000)
				throw (std::invalid_argument(split[1] + ": Value too High (Max 1000)"));
			double BtcValue = FinalValue * btc.getExchangedValue(InputDate);
			// Calcule la conversion Euros -> Btc
			std::cout << GREEN << "On " << FinalDate << ", convert " \
				<< std::fixed << std::setprecision(2) << FinalValue \
				<< " Euros into Btc gives: " << BtcValue << DEFAULT << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Error: " << e.what() \
				<< " (line: " << i << ": " << line << ")" << DEFAULT << std::endl;
		}
		delete [] split;
		i++;
	}
}

time_t CheckDate(std::string date)
{
	struct tm tm;
	memset(&tm, 0, sizeof(struct tm));
	time_t buffer;
	std::string format = "%F"; // means %Y-%0m-%0d;
	
	if (IsEmpty(date))
		throw (std::invalid_argument("No Date provided"));
	if (!strptime(date.c_str(), format.c_str(), &tm))
		throw (std::invalid_argument(date + ": Invalid date format"));
	buffer = mktime(&tm);
	if (buffer == -1)
		throw (std::invalid_argument(date + ": Invalid date format"));
	if (tm.tm_year < 70 || tm.tm_year > 200)
		throw (std::invalid_argument(date + ": Invalid date format"));
	return buffer;
}

void CheckValue(std::string value)
{
	if (IsEmpty(value))
		throw (std::invalid_argument("No Value provided"));
	for (std::string::iterator it = value.begin(); it != value.end(); it++)
	{
		if (!isdigit(*it) && *it != '.' && *it == '-')
			throw (std::invalid_argument(value + ": Invalid value format"));
	}
}


int main(int argc, char **argv)
{
	Btc				*btc = NULL;
	std::fstream	*fd = NULL;
	
	try
	{
		CheckArgs(argc);
		fd = OpenFile(argv[1]);
		btc = new Btc();
		Evaluation(*btc, *fd);
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << "Error: "<< e.what() << DEFAULT << std::endl;
		delete btc;
		delete fd;
		return EXIT_FAILURE;
	}
	std::cout << std::endl << CYAN << "   ===== All Tests Done =====" << DEFAULT << std::endl;
	delete btc;
	delete fd;
	return EXIT_SUCCESS;
	
}
