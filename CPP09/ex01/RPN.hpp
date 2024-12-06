/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:19:43 by pdeson            #+#    #+#             */
/*   Updated: 2024/11/05 10:57:22 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <stack>
#include <cstdlib>
#include "colors.hpp"

class RPN
{
	public:
		RPN(void);
		RPN(std::string expr);
		RPN(RPN const &src);
		~RPN(void);
		RPN &operator=(RPN const &rhs);
		void getResult(void) const;
		int getValueStr(std::string value) const;
	
	private:
		std::stack<int> _stack;
};

void CheckArgs(char *arg);
std::string *SplitStr(std::string &line, char c, size_t &count);
