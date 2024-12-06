/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:53:06 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/24 16:15:08 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WhatEver.hpp"
#include "colors.hpp"
#include <iostream>
#include <string>

int main(void) {
    
    std::cout << CYAN << "Test de la classe WhatEver sur des INT" << DEFAULT << std::endl;
    int a = 2;
    int b = 3;
    std::cout << YELLOW << "\tAvant le swap:\ta: " << a << " b: " << b;
    WhatEver<int>::swap(a, b);
    std::cout << " / et Après: a: " << a << " b: " << b << std::endl;
    std::cout << "\tmin: " << WhatEver<int>::min(a, b) << "\t/\t";
    std::cout << "max: " << WhatEver<int>::max(a, b) << DEFAULT << std::endl << std::endl;

    std::cout << CYAN << "Test de la classe WhatEver sur des STRING" << DEFAULT << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";
    std::cout << YELLOW << "\tAvant le swap:\tc: " << c << " d: " << d;
    WhatEver<std::string>::swap(c, d);
    std::cout << " / et Après: c: " << c << " d: " << d << std::endl;
    std::cout << "\tmin: " << WhatEver<std::string>::min(c, d) << "\t/\t";
    std::cout << "max: " << WhatEver<std::string>::max(c, d) << DEFAULT << std::endl << std::endl;

    std::cout << CYAN << "Test de la classe WhatEver sur des FLOAT" << DEFAULT << std::endl;
    float e = 2.5;
    float f = 3.5;
    std::cout << YELLOW << "\tAvant le swap:\te: " << e << " f: " << f;
    WhatEver<float>::swap(e, f);
    std::cout << " / et Après: e: " << e << " f: " << f << std::endl;
    std::cout << "\tmin: " << WhatEver<float>::min(e, f) << "\t/\t";
    std::cout << "max: " << WhatEver<float>::max(e, f) << DEFAULT << std::endl << std::endl;
    
    std::cout << CYAN << "Test de la classe WhatEver sur des DOUBLE" << DEFAULT << std::endl;
    double g = 2.5;
    double h = 3.5;
    std::cout << YELLOW << "\tAvant le swap:\tg: " << g << " h: " << h;
    WhatEver<double>::swap(g, h);
    std::cout << " / et Après: g: " << g << " h: " << h << std::endl;
    std::cout << "\tmin: " << WhatEver<double>::min(g, h) << "\t/\t";
    std::cout << "max: " << WhatEver<double>::max(g, h) << DEFAULT << std::endl;
    
    return 0;
    
}