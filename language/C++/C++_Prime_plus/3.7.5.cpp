#include <iostream>
int main() {
    long long wp,usp;
    std::cout << "Enter the world's population: ";
    std::cin >> wp;
    
    std::cout << "Enter the population of the US: ";
    std::cin >> usp;

    double p=(usp*100.0)/wp;
    std::cout << "The population of the US is " << p << "% of the world population." << std::endl;
    return 0;
}