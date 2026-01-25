#include <iostream>
int main() {
    const int dpm=60;
    const int mps=60;
    int d,m,s;
    std::cout << "Enter a latitude in degrees, minutes, and seconds:\n";
    std::cout << "First, enter the degrees: ";
    std::cin >> d;
    std::cout << "Next, enter the minutes of arc: ";
    std::cin >> m;
    std::cout << "Finally, enter the seconds of arc: ";
    std::cin >> s;
    double td=d+m/(double)dpm+s/(double)(dpm*mps);
    std::cout << d << " degrees, " << m << " minutes, " << s << " seconds = ";
    std::cout << td << " degrees" << std::endl;
    return 0;
}