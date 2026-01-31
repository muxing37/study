#include <iostream>
#include <fstream>
int main() {
    std::string fn;
    std::cout << "Enter a file name: ";
    std::cin >> fn;
    std::ifstream f(fn);
    if(!f) {
        std::cout << "Error opening file!" << std::endl;
        return 1;
    }
    char ch;
    int c=0;
    while(f.get(ch)) {
        c++;
    }
    std::cout << "The file contains " << c << " characters." << std::endl;
    f.close();
    return 0;
}