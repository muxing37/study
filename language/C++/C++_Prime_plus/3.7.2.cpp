#include <iostream>
using namespace std;

const double IPF=12.0;
const double MPI=0.0254;
const double KPP=1.0/2.2;

int main() {
    int feet,inch;
    double wei;
    cout << "Enter your height in feet: ";
    cin >> feet;
    cout << "Enter your height in inches: ";
    cin >> inch;
    cout << "Enter your weight in pounds: ";
    cin >> wei;
    double tinch=feet*IPF+inch;
    double h=tinch*MPI;
    double weik=wei*KPP;
    double bmi=weik/(h*h);
    cout << "\nHeight: " << feet << " feet " << inch << " inches" << endl;
    cout << "Height in meters: " << h << " m" << endl;
    cout << "Weight in kilograms: " << weik << " kg" << endl;
    cout << "Your BMI is: " << bmi << endl;
    return 0;
}