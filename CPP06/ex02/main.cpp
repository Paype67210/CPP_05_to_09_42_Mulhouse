/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:25:04 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/24 15:33:28 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Functions.hpp"
#include "colors.hpp"
#include <ctime>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

int main() {
    srand(time(NULL));

    // Test avec plusieurs instances
    for (int i = 0; i < 5; i++) {
        Base* instance = generate();
        
        std::cout << CYAN << "Test " << i + 1 << ":" << DEFAULT << std::endl;
        std::cout << YELLOW << "Par pointeur : ";
        identify(instance);
        std::cout << GREEN << "Par reference : ";
        identify(*instance);
        std::cout << CYAN << "-------------------" << DEFAULT << std::endl;
        std::cout << CYAN << "Cleaning up..." << DEFAULT << std::endl << std::endl;
        delete instance;
    }

    return 0;
}