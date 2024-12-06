/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:09:44 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 09:48:36 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "iter.hpp"
#include "colors.hpp"

template <typename T>
void iter(T* array, int length, void (*func)(T&)) {
    for (int i = 0; i < length; ++i) {
        func(array[i]);
    }
}
