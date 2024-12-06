/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 08:31:10 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 12:22:25 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include "colors.hpp"

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
		Bureaucrat();
		
	public:
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		~Bureaucrat();
		Bureaucrat			&operator=(Bureaucrat const &rhs);
		std::string const	&getName() const;
		int					getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
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
