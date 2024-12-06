/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:30:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 12:38:32 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/Bureaucrat.hpp"
#include "./headers/AForm.hpp"
#include "./headers/ShrubberyCreationForm.hpp"
#include "./headers/RobotomyRequestForm.hpp"
#include "./headers/PresidentialPardonForm.hpp"
#include "./headers/Intern.hpp"

void test_subject()
{
	std::cout << BLUE << "✅ Try to create a Robotonomy Request Form" << DEFAULT << std::endl;
	try
	{
		Intern slavette;
		AForm *rrf;
		rrf = slavette.makeForm("Robotomy Request", "Cerfa 007");
		Bureaucrat b1("Bureaucrat 1", 75);
		b1.signForm(*rrf);
		b1.executeForm(*rrf);
		std::cout << "---------------------------------" << std::endl;
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	std::cout << BLUE << "❌ Try to create a Cerfa Form" << DEFAULT << std::endl;
	try
	{
		Intern stagiaire;
		AForm *scf;
		scf = stagiaire.makeForm("Cerfa creation", "Boulette");
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << DEFAULT << '\n';
	}
}

void test_all_forms(void)
{
	try {
		Intern slave;
		AForm *f1 = slave.makeForm("Shrubbery Creation", "Cerfa 28");
		AForm *f2 = slave.makeForm("Robotomy Request", "Cerfa 152");
		AForm *f3 = slave.makeForm("Presidential Pardon", "Cerfa 28B");
		Bureaucrat b1("Bureaucrat 1", 147);
			
		std::cout << "---------------------------------" << std::endl;
		std::cout << b1 << std::endl;
		std::cout << *f1 << std::endl;
		std::cout << *f2 << std::endl;
		std::cout << *f3 << std::endl;
		std::cout << "---------------------------------" << std::endl;
		
		b1.signForm(*f1);
		b1.executeForm(*f1);
	
		delete f1;
		delete f2;
		delete f3;
	}

	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
}

int	main()
{
	srand(time(NULL));

	std::cout << CYAN << std::endl << std::endl \
		<< "======     TEST NAME USAGE     ======" << DEFAULT << std::endl << std::endl;
	test_subject();
	
	std::cout << CYAN << std::endl << std::endl \
		<< "======     TESTS FOR ALL FORMS     ======" << DEFAULT << std::endl << std::endl;
	test_all_forms();
	
	return 0;
}
