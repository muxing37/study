#include <iostream>
using namespace std;
double zh(double l) {
    return l*63240.0;
}

int main() {
    double l,a;
    cout << "Enter the number of light years: ";
    cin >> l;
    a=zh(l);
    cout << l << " light years = " << a << " astronomical units." << endl;
    return 0;
}