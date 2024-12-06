/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:20:26 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 11:27:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "colors.hpp"

template <typename T>
int easyFind(T &container, int toFind)
{
	typename T::iterator it = std::find(container.begin(), container.end(), toFind);
	if (it == container.end())
		throw std::runtime_error("Element not found");
	return *it;
}
