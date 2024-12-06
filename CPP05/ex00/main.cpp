/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:30:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/21 09:21:01 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b1("Bureaucrat1", 1);
		std::cout << b1 << std::endl;
		std::cout << CYAN << "Trying to increment grade" << DEFAULT << std::endl;
		b1.incrementGrade();
		// Ne doit pas executer ce qui suit dans le cas où l'exception est levée
		std::cout << b1 << std::endl;
		std::cout << CYAN << "Trying to decrement grade" << DEFAULT << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		Bureaucrat b2("Bureaucrat2", 150);
		std::cout << b2 << std::endl;
		std::cout << CYAN << "Trying to decrement grade" << DEFAULT << std::endl;
		b2.decrementGrade();
		// Ne doit pas executer ce qui suit dans le cas où l'exception est levée
		std::cout << b2 << std::endl;
		std::cout << CYAN << "Trying to increment grade" << DEFAULT << std::endl;
		b2.incrementGrade();
		std::cout << b2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		std::cout << CYAN << "Trying to create a bureaucrat with a grade of 0" << DEFAULT << std::endl;
		Bureaucrat b3("Bureaucrat3", 0);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		std::cout << CYAN << "Trying to create a bureaucrat with a grade of 151" << DEFAULT << std::endl;
		Bureaucrat b4("Bureaucrat4", 151);
	}
	catch (std::exception &e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	try
	{
		Bureaucrat b5("Bureaucrat5", 50);
		std::cout << b5 << std::endl;
		std::cout << CYAN << "Trying to increment grade" << DEFAULT << std::endl;
		b5.incrementGrade();
		std::cout << b5 << std::endl;
		std::cout << CYAN << "Trying to decrement grade 3 times" << DEFAULT << std::endl;
		b5.decrementGrade();
		b5.decrementGrade();
		b5.decrementGrade();
		std::cout << b5 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	return 0;
}