/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:14:57 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/24 15:07:36 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stdint.h>
#include "Data.hpp"
#include "colors.hpp"

class Serializer
{
    private:
        // Constructeur privé pour empêcher l'instanciation
        Serializer();
        // Opérateur de copie privé
        Serializer(const Serializer& other);
        // Opérateur d'affectation privé
        Serializer& operator=(const Serializer& other);
        // Destructeur privé
        ~Serializer();

    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};