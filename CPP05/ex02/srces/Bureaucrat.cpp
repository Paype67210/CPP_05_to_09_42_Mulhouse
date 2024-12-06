/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:31:21 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 11:16:10 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/AForm.hpp"

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cerr << GREY << "\t" << _name << " has been created" << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	std::cerr << GREY << "\t" << _name << " has been destroyed" << DEFAULT << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	_grade = rhs._grade;
	return *this;
}

std::string const Bureaucrat::getName() const { return _name; }

int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incrementGrade(int value)
{
	if (_grade - value < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade -= value;
}

void	Bureaucrat::decrementGrade(int value)
{
	if (_grade + value > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade += value;
}

void	Bureaucrat::signForm(AForm &formName)
{
	if (_grade >= formName.getSignGrade() && formName.getIsSigned() == false) {
		formName.beSigned(*this);
		std::cout << GREEN << _name << " signs " << formName.getName() << DEFAULT << std::endl;
	}
	else
		std::cout << RED << _name << " cannot sign " << formName.getName() << " because his grade is too low" << DEFAULT << std::endl;
}

void	Bureaucrat::executeForm(AForm const &formName) const
{
	if (formName.getIsSigned() == false)
		std::cout << RED << _name << " cannot execute " << formName.getName() << " because it is not signed" << DEFAULT << std::endl;
	else if (_grade >= formName.getExecGrade() && formName.getIsSigned() == true)
		std::cout << GREEN << _name << " executes " << formName.getName() << DEFAULT << std::endl;
	else
		std::cout << RED << _name << " cannot execute " << formName.getName() << " because his grade is too low" << DEFAULT << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << GREEN << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << DEFAULT;
	return o;
}
