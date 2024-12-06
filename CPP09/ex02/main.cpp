/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:55:49 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/25 11:16:47 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool IsNumber(const std::string &str)
{
	if (str.empty()) return false;
	for (size_t i = 0; i < str.length(); i++)
		if (!isdigit(str[i])) return false;
	return true;
}

template <typename Container>
void displayContainer(const Container &container, const std::string &name)
{
	std::cout << GREY << name << ": (";
	typename Container::const_iterator it;
	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << ")" << DEFAULT << std::endl;
}

int	main(int argc, char **argv)
{
	std::vector<int> numbers;
	
	srand(time(NULL));
	try
	{
		if (argc == 1)
			throw std::invalid_argument("No argument provided");
		else if (argc == 2)
		{
			std::istringstream stream(argv[1]);
			std::string token;
			
			while(stream >> token) {
				if (IsNumber(token)) {
					int buffer = std::strtod(token.c_str(), NULL);
					if (buffer >= 0)
						numbers.push_back(buffer);
					else
						throw (std::invalid_argument("Negative value"));
				}
				else
					throw (std::invalid_argument("Invalid value"));
			}
		}
		else
		{
			for (int i = 1; i < argc; i++)
			{
				if (IsNumber(argv[i])) {
					int buffer = std::strtod(argv[i], NULL);
					if (buffer >= 0)
						numbers.push_back(buffer);
					else
						throw (std::invalid_argument("Negative value"));
				}
				else
					throw (std::invalid_argument("Invalid value"));
			}
		}
		// Suite du traitement
		std::cout << CYAN << "Before: ";
		displayContainer(numbers, "Original");
		std::cout << DEFAULT << std::endl;
		
		// Realisation du tri pour un vector
		{
			std::vector<int> vecNumbers(numbers);
			PmergeMe<int, std::vector<int> > sorterVec(vecNumbers);
		
			// Realisation du tri pour un vecteur
			// Initialiser le temps
			std::clock_t startV = std::clock();
			std::vector<int> resultVec = sorterVec.sort();
			// compter le temps ecoule et l'afficher
			std::clock_t endV = std::clock();
			double elapsed_timeV = double(endV - startV) / CLOCKS_PER_SEC;
			std::cout << YELLOW << "\nAfter Vector sort: " << std::endl;
			displayContainer(resultVec, "Vector Sorted");
			std::cout << RED << "Time to process with std::vector: " << elapsed_timeV << "s" << std::endl;
			std::cout << "--------------------------------" << DEFAULT << std::endl;
		}
		
		// Realisation du tri pour une list
		{
			std::list<int> listNumbers(numbers.begin(), numbers.end());
			PmergeMe<int, std::list<int> > sorterList(listNumbers);
			// Realisation du tri pour un vecteur
			// Initialiser le temps
			std::clock_t startL = std::clock();
			std::list<int> resultLst = sorterList.sort();
			// compter le temps ecoule et l'afficher
			std::clock_t endL = std::clock();
			double elapsed_timeL = double(endL - startL) / CLOCKS_PER_SEC;
			std::cout << YELLOW << "\nAfter List sort: " << std::endl;
			displayContainer(resultLst, "List Sorted");
			std::cout << RED << "Time to process with std::list: " << elapsed_timeL << "s" << std::endl;
			std::cout << "--------------------------------" << DEFAULT << std::endl;
		}
	
		// Realisation du tri pour un deque
		{
			std::deque<int> dequeNumbers(numbers.begin(), numbers.end());
			PmergeMe<int, std::deque<int> > sorterDeque(dequeNumbers);
			// Realisation du tri pour un vecteur
			// Initialiser le temps
			std::clock_t startD = std::clock();
			std::deque<int> resultDeque = sorterDeque.sort();
			// compter le temps ecoule et l'afficher
			std::clock_t endD = std::clock();
			double elapsed_timeD = double(endD - startD) / CLOCKS_PER_SEC;
			std::cout << YELLOW << "\nAfter Deque sort: " << std::endl;
			displayContainer(resultDeque, "Deque Sorted");
			std::cout << RED << "Time to process with std::deque: " << elapsed_timeD << "s" << std::endl;
			std::cout << "--------------------------------" << DEFAULT << std::endl;
		}
	
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	return 0;

}
