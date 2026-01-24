#include <iostream>
using namespace std;
double cf(double c) {
    return 1.8*c+32.0;
}
int main() {
    double c,f;
    cout << "Please enter a Celsius value: ";
    cin >> c;
    f=cf(c);
    cout << c << " degrees Celsius is " << f << " degrees Fahrenheit." << endl;
    return 0;
}