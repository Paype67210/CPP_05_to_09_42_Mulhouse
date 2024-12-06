/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:31:32 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 11:16:21 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : \
	AForm("RobotomyRequestForm", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : AForm(src)
{
	this->operator=(src);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

void RobotomyRequestForm::executeImpl(Bureaucrat const &executor) const
{
	(void)executor;
	
    std::cerr << GREY << "\t" << executor.getName() << " executes " << this->getName() << DEFAULT << std::endl;
	std::cout << "* 🎶 🎶 🎶 🎶 drilling noises 🎶 🎶 🎶 🎶 *" << std::endl;
	if (rand() % 2)
		std::cout << this->getTarget() << BLUE \
			<< " has been robotomized successfully" << DEFAULT << std::endl;
	else
		std::cout << this->getTarget() << YELLOW \
			<< " failed to be robotomized" << DEFAULT << std::endl;
}
