/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:25:32 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 12:37:22 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Intern.hpp"
#include "../headers/ShrubberyCreationForm.hpp"
#include "../headers/RobotomyRequestForm.hpp"
#include "../headers/PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern() {}

Intern &Intern::operator=(Intern const &rhs)
{
	if (this == &rhs)
		return *this;
	return *this;
}

AForm *Intern::makeForm(std::string const &TypeForm, std::string const &target)
{
	AForm *(*formPointers[3])(std::string const &target) = { \
		Intern::createShrubberyCreationForm, \
		Intern::createRobotomyRequestForm, \
		Intern::createPresidentialPardonForm };
	std::string const Type[3] = { "Shrubbery Creation", "Robotomy Request", "Presidential Pardon" };
	for (int i = 0; i < 3; i++)
	{
		if (Type[i] == TypeForm) {
			std::cout \
				<< GREEN "[   FORMS   ]" DEFAULT << std::endl \
				<< "Intern creates " << YELLOW << TypeForm << DEFAULT << " form" \
				<< " (" << target << ")" << std::endl;
			return formPointers[i](target);
		}
	}
	throw Intern::UnknownFormException();
}

AForm *Intern::createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

const char *Intern::UnknownFormException::what() const throw()
{
	return "Unknown form";
}

