#include <iostream>

struct CandyBar {
    char brd[50];
    double wg;
    int cal;
};
int main() {
    CandyBar snack = {"Mocha Munch", 2.3, 350};
    
    std::cout << "Brand: " << snack.brd << std::endl;
    std::cout << "Weight: " << snack.wg << std::endl;
    std::cout << "Calories: " << snack.cal << std::endl;
    
    return 0;
}