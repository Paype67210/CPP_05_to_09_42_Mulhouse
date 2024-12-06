/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:25:54 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 12:20:30 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		AForm(std::string name, std::string &target, int signGrade, int execGrade);
		AForm(AForm const &src);
		virtual ~AForm();

		AForm &operator=(AForm const &rhs);

		// Getters
		std::string	getName() const;
		std::string	getTarget() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;

		// Methods
		void 			beSigned(Bureaucrat const &bureaucrat);
		void 			execute(Bureaucrat const &executor) const;
		virtual void 	executeImpl(Bureaucrat const &executor) const = 0;

		// Exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		AForm();
		std::string const	_name;
		std::string const	_target;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;
};

std::ostream &operator<<(std::ostream &o, AForm const &i);
