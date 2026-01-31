#include <iostream>
#include <cstring>
int main() {
    char w[50];
    int c=0;
    std::cout << "Enter words (to stop, type the word done):\n";
    while(std::cin >> w) {
        if(strcmp(w,"done")==0) {
            break;
        }
        c++;
    }
    std::cout << "You entered a total of " << c << " words." << std::endl;
    return 0;
}