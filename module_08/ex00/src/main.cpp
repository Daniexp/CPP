#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::cout << "The proyect was created sucessfully." << std::endl;
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        int valueToFind = 3;
        std::vector<int>::iterator result = easyfind(vec, valueToFind);
        std::cout << "Value " << valueToFind << " found at index: " << std::distance(vec.begin(), result) << std::endl;
        easyfind(vec, -100000);
    } catch (const std::runtime_error& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

