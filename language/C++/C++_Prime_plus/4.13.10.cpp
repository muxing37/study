#include <iostream>
#include <array>
int main() {
    std::array<double,3> t;

    std::cout << "Enter first 40m run time: ";
    std::cin >> t[0];
    std::cout << "Enter second time: ";
    std::cin >> t[1];
    std::cout << "Enter third time: ";
    std::cin >> t[2];

    double avg=(t[0]+t[1]+t[2])/3;
    std::cout << "Times: " << t[0] << ", " << t[1] << ", " << t[2] << std::endl;
    std::cout << "Average: " << avg << std::endl;
    return 0;
}