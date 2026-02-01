#include <iostream>
double tiaohe(double x, double y) {
    return 2.0*x*y/(x+y);
}
int main() {
    double a, b;
    while(1) {
        std::cout << "Enter two numbers (0 to quit): ";
        std::cin >> a >> b;
        if(a==0 || b==0) {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        double res=tiaohe(a, b);
        std::cout << "Harmonic mean: " << res << std::endl;
    }
    return 0;
}