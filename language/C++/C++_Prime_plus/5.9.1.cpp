#include <iostream>
int main() {
    int a,b;
    int sum=0;
    std::cout << "Enter two number: ";
    std::cin >> a;
    std::cin >> b;
    if(a>b) {
        int t=a;
        a=b;
        b=t;
    }
    for(int i=a;i<=b;i++) {
        sum += i;
    }
    std::cout << "Sum of integers from " << a << " to " << b << " is " << sum << std::endl;
    return 0;
}