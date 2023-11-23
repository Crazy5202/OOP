#include <iostream>
#include "nod.hpp"

int main() {
    int a,b;
    std::cout << "Введите два числа для нахождения их НОД: ";
    std::cin >> a >> b;
    std::cout << "НОД: " << nod(a,b) << std::endl;
}