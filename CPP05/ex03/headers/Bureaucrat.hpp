/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:31:10 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 12:16:48 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "colors.hpp"
#include "Bureaucrat.hpp"

#define MAX_GRADE 1
#define MIN_GRADE 150
class AForm;

class Bureaucrat
{
	private:
		Bureaucrat();
		std::string const _name;
		int _grade;
		
	public:
		Bureaucrat(std::string const &name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat			&operator=(Bureaucrat const &rhs);

		// Getters
		std::string const	getName() const;
		int					getGrade() const;
		void				incrementGrade(int value);
		void				decrementGrade(int value);
		void				signForm(AForm &formName);
		void				executeForm(AForm const &formName) const;

		// Exceptions
		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);
