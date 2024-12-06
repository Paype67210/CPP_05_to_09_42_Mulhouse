/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:28:04 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/21 13:13:05 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _isSigned(false)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
	std::cerr << GREY << _name << " has been created" << DEFAULT << std::endl;

}

Form::Form(Form const &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
}

Form::~Form()
{
}

Form &Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	return *this;
}

std::string Form::getName() const
{
	return _name;
}

int Form::getSignGrade() const
{
	return _signGrade;
}	

int Form::getExecGrade() const
{
	return _execGrade;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() < _signGrade)
		throw Form::GradeTooLowException();
	_isSigned = true;
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!_isSigned)
		throw Form::GradeTooLowException();
	if (executor.getGrade() < _execGrade)
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << GREEN << "Form " << i.getName() << " is ";
	if (i.getIsSigned())
		o << "signed";
	else
		o << YELLOW << "not signed" << GREEN;
	o << " and requires grade " << YELLOW << i.getSignGrade() << GREEN \
		<< " to be signed and grade " << YELLOW << i.getExecGrade() << GREEN \
		<< " to be executed" << DEFAULT;
	return o;
}
