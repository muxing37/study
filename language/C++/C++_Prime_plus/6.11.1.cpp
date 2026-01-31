#include <iostream>
#include <cctype>
int main() {
    char ch;
    std::cout << "Enter text (end with @):\n";
    while(std::cin.get(ch) && ch!='@') {
        if(isdigit(ch)) {
            continue;
        } else if(isupper(ch)) {
            ch=tolower(ch);
        } else if(islower(ch)) {
            ch=toupper(ch);
        }
        std::cout << ch;
    }
    return 0;
}