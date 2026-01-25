#include <iostream>
#include <cstring>

int main() {
    const int sz=100;
    char fn[sz],ln[sz],rs[sz*2]={0};
    
    std::cout << "Enter your first name: ";
    std::cin >> fn;
    std::cout << "Enter your last name: ";
    std::cin >> ln;

    strcpy(rs, ln);
    strcat(rs, ", ");
    strcat(rs, fn);
    std::cout << "Here's the information in a single string: " << rs << std::endl;
    return 0;
}