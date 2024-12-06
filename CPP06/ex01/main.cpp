/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:14:40 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/24 15:11:09 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Serializer.hpp"

int main() {
    // Création d'un objet Data
    std::cout << CYAN << "Creating Data object..." << DEFAULT << std::endl;
    Data* originalData = new Data;
    originalData->value = 42;
    originalData->character = 'A';
    originalData->flag = true;

    // Test de sérialisation
    std::cout << GREEN << "Reinterpret cast test" << DEFAULT << std::endl;
    uintptr_t serialized = Serializer::serialize(originalData);
    Data* deserialized = Serializer::deserialize(serialized);

    // Vérification
    std::cout << YELLOW << "Original pointer: " << originalData << std::endl;
    std::cout << "Deserialized pointer: " << deserialized << std::endl;
    std::cout << "Comparison: " << (originalData == deserialized ? "SUCCESS" : "FAILURE") << DEFAULT << std::endl;

    // Vérification des valeurs
    std::cout << GREEN << "\nVerifying values:" << DEFAULT << std::endl;
    std::cout << "Value: " << deserialized->value << RED << " (expected: 42)" << DEFAULT << std::endl;
    std::cout << "Character: " << deserialized->character << RED << " (expected: A)" << DEFAULT << std::endl;
    std::cout << "Flag: " << deserialized->flag << RED << " (expected: 1)" << DEFAULT << std::endl;

    // Nettoyage
    std::cout << CYAN << "\nCleaning up..." << DEFAULT << std::endl;
    delete originalData;

    return 0;
}