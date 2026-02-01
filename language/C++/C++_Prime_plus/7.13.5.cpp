#include <iostream>
unsigned long long fact(int n) {
    if(n==0) return 1;
    return n*fact(n-1);
}
int main() {
    int n;
    std::cout << "Enter an number (negative to quit): ";
    while(std::cin >> n && n >= 0) {
        unsigned long long res=fact(n);
        std::cout << n << "! = " << res << std::endl;
        std::cout << "Enter another number (negative to quit): ";
    }
    std::cout << "Done." << std::endl;
    return 0;
}