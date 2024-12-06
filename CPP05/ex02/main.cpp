/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:30:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 11:17:22 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/Bureaucrat.hpp"
#include "./headers/AForm.hpp"
#include "./headers/ShrubberyCreationForm.hpp"
#include "./headers/RobotomyRequestForm.hpp"
#include "./headers/PresidentialPardonForm.hpp"

void test_Shrubberry(void)
{
	Bureaucrat b1("Bureaucrat 1", 137);
	Bureaucrat b2("Bureaucrat 2", 145);
	ShrubberyCreationForm f1("ShrubberyCreationForm 1");
	ShrubberyCreationForm f2("ShrubberyCreationForm 2");

	std::cout << "---------------------------------" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << "---------------------------------" << std::endl;

	try {
		std::cerr << CYAN << "Trying to sign a form with a grade too low" << DEFAULT << std::endl;
		b1.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cerr << CYAN << "Trying to sign a form with a good grade" << DEFAULT << std::endl;
		b2.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		std::cerr << CYAN << "Trying to execute a form NOT signed" << DEFAULT << std::endl;
		b2.executeForm(f2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		std::cerr << CYAN << "Trying to execute a form already signed" << DEFAULT << std::endl;
		b2.signForm(f2);
		f2.executeImpl(b2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
}

void test_Robotomy(void)
{
	Bureaucrat b1("Bureaucrat 1", 45);
	Bureaucrat b2("Bureaucrat 2", 72);
	RobotomyRequestForm f1("RobotomyRequestForm 1");
	RobotomyRequestForm f2("RobotomyRequestForm 2");

	std::cout << "---------------------------------" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << "---------------------------------" << std::endl;

	try {
		std::cerr << CYAN << "Trying to sign a form with a grade too low" << DEFAULT << std::endl;
		b1.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cerr << CYAN << "Trying to sign a form with a good grade" << DEFAULT << std::endl;
		b2.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		std::cerr << CYAN << "Trying to execute a form NOT signed" << DEFAULT << std::endl;
		b2.executeForm(f2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		std::cerr << CYAN << "Trying to execute a form already signed 10 times" << DEFAULT << std::endl;
		b2.signForm(f2);
		for (int i = 0; i < 10; i++)
			f2.executeImpl(b2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

}

void test_PresidentialPardon(void)
{
	Bureaucrat b1("Bureaucrat 1", 5);
	Bureaucrat b2("Bureaucrat 2", 25);
	PresidentialPardonForm f1("PresidentialPardonForm 1");
	PresidentialPardonForm f2("PresidentialPardonForm 2");

	std::cout << "---------------------------------" << std::endl;
	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;
	std::cout << "---------------------------------" << std::endl;

	try {
		std::cerr << CYAN << "Trying to sign a form with a grade too low" << DEFAULT << std::endl;
		b1.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cerr << CYAN << "Trying to sign a form with a good grade" << DEFAULT << std::endl;
		b2.signForm(f1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		std::cerr << CYAN << "Trying to execute a form NOT signed" << DEFAULT << std::endl;
		b2.executeForm(f2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		std::cerr << CYAN << "Trying to execute a form already signed" << DEFAULT << std::endl;
		b2.signForm(f2);
		f2.executeImpl(b2);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

int	main()
{
	srand(time(NULL));
	std::cout << CYAN << std::endl << std::endl \
		<< "======     TESTS SHRUBBERY CREATION     ======" << DEFAULT << std::endl << std::endl;
	test_Shrubberry();
	
	std::cout << CYAN << std::endl << std::endl \
		<< "======     TESTS ROBOTOMY REQUEST     ======" << DEFAULT << std::endl << std::endl;
	test_Robotomy();
	
	std::cout << CYAN << std::endl << std::endl \
		<< "======     TESTS PRESIDENTIAL PARDON     ======" << DEFAULT << std::endl << std::endl;
	test_PresidentialPardon();
	
	return 0;
}
