#include <iostream>
using namespace std;
void display(int hours, int minutes) {
    cout << "Time: " << hours << ":" << minutes << endl;
}

int main() {
    int h,min;
    cout << "Enter the number of hours: ";
    cin >> h;
    cout << "Enter the number of minutes: ";
    cin >> min;
    display(h,min);
    return 0;
}