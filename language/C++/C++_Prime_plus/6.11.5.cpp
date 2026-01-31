#include <iostream>
int main() {
    double a;
    while(1) {
        std::cout << "Enter income (negative or non-numeric to quit): ";
        std::cin >> a;
        if (std::cin.fail() || a < 0) {
            break;
        }
        double tax=0.0;
        if(a>35000) {
            tax += (a-35000)*0.20;
            a=35000;
        }
        if(a>15000) {
            tax += (a-15000)*0.15;
            a=15000;
        }
        if(a>5000) {
            tax += (a-5000)*0.10;
        }
        std::cout << "Tax: " << tax << " tvarps" << std::endl;
    }
    return 0;
}