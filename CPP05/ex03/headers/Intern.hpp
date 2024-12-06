/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:20:05 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 11:25:18 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class Intern
{
	private:
		static AForm *createShrubberyCreationForm(std::string const &target);
		static AForm *createRobotomyRequestForm(std::string const &target);
		static AForm *createPresidentialPardonForm(std::string const &target);
		
	public:
		Intern();
		Intern(Intern const &src);
		~Intern();

		Intern &operator=(Intern const &rhs);

		AForm *makeForm(std::string const &TypeForm, std::string const &target);
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		
};
