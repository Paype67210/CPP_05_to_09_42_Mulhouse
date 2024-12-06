/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:31:21 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/21 13:14:31 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cerr << GREY << _name << " has been created" << DEFAULT << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name)
{
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	std::cerr << GREY << _name << " has been destroyed" << DEFAULT << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	_grade = rhs._grade;
	return *this;
}

std::string const &Bureaucrat::getName() const { return _name; }

int	Bureaucrat::getGrade() const { return _grade; }

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form &formName)
{
	if (_grade >= formName.getSignGrade() && formName.getIsSigned() == false) {
		formName.beSigned(*this);
		std::cout << GREEN << _name << " signs " << formName.getName() << DEFAULT << std::endl;
	}
	else
		std::cout << RED << _name << " cannot sign " << formName.getName() << " because his grade is too low" << DEFAULT << std::endl;
}

void	Bureaucrat::executeForm(Form const &formName) const
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
