/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:11:19 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/24 18:30:44 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Fonction pour être utilisée dans iter
void printInt(int& n) {
    std::cout << n << " ";
}

void printFloat(float& n) {
    std::cout << n << " ";
}

void increment(int& n) {
    n -= 42;
}

void increment(float& n) {
    n += 13;
}

// Classe canonique Test
class Test {
public:
    Test(void) : _value(0) {}
    Test(int value) : _value(value) {}
    Test(const Test& src) { *this = src; }
    Test& operator=(const Test& rhs) {
        if (this != &rhs)
            this->_value = rhs._value;
        return *this;
    }
    ~Test(void) {}

    int getValue(void) const { return _value; }
    void increment(void) { _value += 42; }

private:
    int _value;
};

// Fonction pour afficher la classe Test
void printClass(Test& obj) {
    std::cout << obj.getValue() << " ";
}

// Fonction pour incrémenter la valeur de la classe Test
void incrementClass(Test& obj) {
    obj.increment();
};

int main() {
    std::cout << CYAN << "Test avec un tableau d'INT (Retire 42)" << DEFAULT << std::endl;
    int array[] = {1, 2, 3, 4, 5};
    std::cout << YELLOW << "Array before increment: ";
    iter(array, 5, printInt);
    std::cout << GREEN << "\nArray after increment: ";
    iter(array, 5, increment);
    iter(array, 5, printInt);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << CYAN << "Test avec un tableau de FLOAT (Ajoute 13)" << DEFAULT << std::endl;
    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << YELLOW << "FloatArray before increment: ";
    iter(floatArray, 5, printFloat);
    std::cout << GREEN << "\nFloatArray after increment: ";
    iter(floatArray, 5, increment);
    iter(floatArray, 5, printFloat);
    std::cout << DEFAULT << std::endl << std::endl;

    std::cout << CYAN << "Test avec un tableau de classes TEST (Ajoute 42)" << DEFAULT << std::endl;
    Test testArray[] = {Test(10), Test(20), Test(30)};
    std::cout << YELLOW << "TestArray before increment: ";
    iter(testArray, 3, printClass);
    std::cout << GREEN << "\nTestArray after increment: ";
    iter(testArray, 3, incrementClass);
    iter(testArray, 3, printClass);
    std::cout << DEFAULT << std::endl;

    return 0;
}