#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    // MainTest provided by Intra42
    std::cout << CYAN << "MainTest provided by Intra42" << DEFAULT << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    std::cout << YELLOW << "create a mirror of numbers" << std::endl;
    std::cout << "if mirror != numbers, it's a problem" << DEFAULT << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << GREEN << "OK" << DEFAULT << std::endl;
    try
    {
        std::cout << "numbers[-2] should catch an exception" << std::endl;
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DEFAULT << std::endl;
    }
    try
    {
        std::cout << "numbers[" << MAX_VAL << "] should catch an exception" << std::endl;
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << RED << e.what() << DEFAULT << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    
    // Personnal tests
    std::cout << std::endl;
    std::cout << CYAN << "Personnal tests" << DEFAULT << std::endl;
    std::cout << YELLOW << "Create an array of 10 integers" << DEFAULT << std::endl;
    Array<int> arr(10);
    std::cout << "Array size: " << arr.size() << std::endl;
    std::cout << YELLOW << "Fill the array with 10 random integers" << DEFAULT << std::endl;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = rand();
    }
    std::cout << "Array content: " << arr << std::endl;
    std::cout << YELLOW << "Create a copy of the array" << DEFAULT << std::endl;
    Array<int> arr2(arr);
    std::cout << "Array 2 content: " << arr2 << std::endl;
    std::cout << YELLOW << "Modify the first array" << DEFAULT << std::endl;
    for (unsigned int i = 0; i < arr.size(); ++i) {
        arr[i] = rand();
    }
    std::cout << "Array content: " << arr << std::endl;
    std::cout << "Array 2 content: " << arr2 << std::endl;
    std::cout << YELLOW << "Modify the second array" << DEFAULT << std::endl;
    for (unsigned int i = 0; i < arr2.size(); ++i) {
        arr2[i] = rand();
    }
    std::cout << "Array content: " << arr << std::endl;
    std::cout << "Array 2 content: " << arr2 << std::endl;
    std::cout << YELLOW << "Create an array of 0 integers" << DEFAULT << std::endl;
    Array<int> arr3(0);
    std::cout << "Array 3 size: " << arr3.size() << std::endl;
    std::cout << YELLOW << "Try to access an element of the array of 0 integers" << DEFAULT << std::endl;
    try {
        arr3[0] = 42;
    } catch (std::exception &e) {
        std::cerr << RED << e.what() << DEFAULT << std::endl;
    }
    
    std::cout << YELLOW << "Create an array of 5 strings" << DEFAULT << std::endl;
    Array<std::string> arr4(5);
    std::cout << "Array 4 size: " << arr4.size() << std::endl;
    std::cout << YELLOW << "Fill the array with 5 strings" << DEFAULT << std::endl;
    arr4[0] = "Hello";
    arr4[1] = "World";
    arr4[2] = "!";
    arr4[3] = "How";
    arr4[4] = "are you?";
    std::cout << "Array 4 content: " << arr4 << std::endl;
    std::cout << YELLOW << "Create a copy of the array of strings" << DEFAULT << std::endl;
    Array<std::string> arr5(arr4);
    std::cout << "Array 5 content: " << arr5 << std::endl;
    std::cout << YELLOW << "Modify the first array of strings" << DEFAULT << std::endl;
    arr4[0] = "Bonjour";
    arr4[1] = "le";
    arr4[2] = "monde";
    arr4[3] = "!";
    arr4[4] = "Comment ça va?";
    std::cout << "Array 4 content: " << arr4 << std::endl;
    std::cout << "Array 5 content: " << arr5 << std::endl;
    std::cout << YELLOW << "Modify the second array of strings" << DEFAULT << std::endl;
    arr5[0] = "Hallo";
    arr5[1] = "Welt";
    arr5[2] = "!";
    arr5[3] = "Wie";
    arr5[4] = "geht's?";
    std::cout << "Array 4 content: " << arr4 << std::endl;
    std::cout << "Array 5 content: " << arr5 << std::endl;

    return 0;
}
