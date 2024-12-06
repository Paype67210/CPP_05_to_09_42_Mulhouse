/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WhatEver.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:49:30 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 09:45:21 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
class WhatEver {
    public:
        static void swap(T &a, T &b);
        static const T &min(const T &a, const T &b);
        static const T &max(const T &a, const T &b);
};

template <typename T>
void WhatEver<T>::swap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T &WhatEver<T>::min(const T &a, const T &b) {
    return (a < b ? a : b);
}

template <typename T>
const T &WhatEver<T>::max(const T &a, const T &b) {
    return (a > b ? a : b);
}
