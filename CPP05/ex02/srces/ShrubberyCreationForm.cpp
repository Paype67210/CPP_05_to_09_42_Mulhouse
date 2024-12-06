/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:56:40 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/22 11:16:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : \
    AForm("ShrubberyCreationForm", target, 145, 137)
{
}
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
    this->operator=(src);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
        AForm::operator=(rhs);
    return *this;
}

void ShrubberyCreationForm::executeImpl(Bureaucrat const &executor) const
{
    // (void)executor;
    
    std::cerr << GREY << "\t" << executor.getName() << " executes " << this->getName() << DEFAULT << std::endl;
    std::string fileName = executor.getName() + "_shrubbery.txt";
    std::ofstream outfile(fileName.c_str());
    if (!outfile.is_open())
        throw std::runtime_error("Cannot open file");
    outfile << "       _-_\n"
            "    /~~   ~~\\\n"
            " /~~         ~~\\\n"
            "{               }\n"
            " \\  _-     -_  /\n"
            "   ~  \\\\ //  ~\n"
            "_- -   | | _- _\n"
            "  _ -  | |   -_\n"
            "      // \\\\" << std::endl;
    outfile.close();
}