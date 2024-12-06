/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:28:04 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 11:15:47 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/AForm.hpp"

AForm::AForm(std::string name, std::string &target, int signGrade, int execGrade) : \
	_name(name), \
	_target(target), \
	_signGrade(signGrade), \
	_execGrade(execGrade), \
	_isSigned(false)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw AForm::GradeTooLowException();
	std::cerr << GREY << "\t" << "AForm " << _name << " has been created" << DEFAULT << std::endl;
}

AForm::AForm(AForm const &src) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade), _isSigned(src._isSigned)
{
	std::cerr << GREY << "\t" << "AForm Copy Constructor called" << DEFAULT << std::endl;
}

AForm::~AForm()
{
	std::cerr << GREY << "\t" << "AForm " << _name << " has been destructed" << DEFAULT << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	if (this != &rhs)
	{
		_isSigned = rhs._isSigned;
	}
	std::cerr << GREY << "\t" << "AForm Copy Assignment operator called" << DEFAULT << std::endl;
	return *this;
}

// Getters
std::string AForm::getName() const
{
	return _name;
}

std::string AForm::getTarget() const
{
	return _target;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}	

int AForm::getExecGrade() const
{
	return _execGrade;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

// Methods
void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (this->getIsSigned())
		throw AForm::FormAlreadySignedException();
	if (bureaucrat.getGrade() < _signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() < _execGrade)
		throw AForm::GradeTooLowException();
	this->executeImpl(executor);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::FormAlreadySignedException::what() const throw()
{
	return "Form is already signed";
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << MAGENTA << "[   AForm - " << i.getName() << "  ] " << DEFAULT << std::endl \
		<< i.getTarget() << " is ";
	if (i.getIsSigned())
		o << "signed";
	else
		o << YELLOW << "not signed" << DEFAULT;
	o << " and requires grade " << YELLOW << i.getSignGrade() << DEFAULT \
		<< " to be signed and grade " << YELLOW << i.getExecGrade() << DEFAULT \
		<< " to be executed";
	return o;
}
