/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:30:58 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/21 13:11:48 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat b1("Bureaucrat 1", 1);
	Bureaucrat b2("Bureaucrat 2", 150);
	Form f1("Form 1", 1, 1);
	Form f2("Form 2", 150, 150);

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	try {
		std::cerr << CYAN << "Trying to create a form with a SignGrade too high" << DEFAULT << std::endl;
		Form f3("Form 3", 0, 1);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		std::cerr << CYAN << "Trying to create a form with an ExecGrade too low" << DEFAULT << std::endl;
		Form f4("Form 4", 1, 151);
	} catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		Form f5("Form 5", 150, 150);
		std::cerr << CYAN << "Trying to sign a form with a grade too low" << DEFAULT << std::endl;
		b1.signForm(f5);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		Form f6("Form 6", 120, 150);
		std::cerr << CYAN << "Trying to sign a form with a good grade" << DEFAULT << std::endl;
		b2.signForm(f6);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		Form f7("Form 7", 1, 150);
		std::cerr << CYAN << "Trying to sign a form with a good grade" << DEFAULT << std::endl;
		b1.signForm(f7);
		std::cerr << CYAN << "Trying to execute a form with a grade too low" << DEFAULT << std::endl;
		b1.executeForm(f7);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}

	try {
		Form f8("Form 8", 100, 100);
		std::cerr << CYAN << "Trying to execute a form NOT signed" << DEFAULT << std::endl;
		b2.executeForm(f8);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	try {
		Form f9("Form 9", 100, 100);
		std::cerr << CYAN << "Sign the form AND execute it after" << DEFAULT << std::endl;
		b2.signForm(f9);
		b2.executeForm(f9);
	}
	catch (std::exception &e) {
		std::cerr << RED << e.what() << DEFAULT << std::endl;
	}
	
	
}
