/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:25:54 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/21 09:46:53 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		Form(std::string name, int signGrade, int execGrade);
		Form(Form const &src);
		~Form();

		Form &operator=(Form const &rhs);

		std::string	getName() const;
		int			getSignGrade() const;
		int			getExecGrade() const;
		bool		getIsSigned() const;

		void beSigned(Bureaucrat const &bureaucrat);
		void execute(Bureaucrat const &executor) const;

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

	private:
		Form();
		std::string const	_name;
		int const			_signGrade;
		int const			_execGrade;
		bool				_isSigned;
};

std::ostream &operator<<(std::ostream &o, Form const &i);
