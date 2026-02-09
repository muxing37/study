#include <iostream>
#include <cstring>

struct CandyBar {
    char brd[50];
    float wgt;
    int cal;
};

void set(CandyBar& cb,const char* b="Millennium Munch",double w=2.85,int c=350) {
    strcpy(cb.brd,b);
    cb.wgt=w;
    cb.cal=c;
}

void sh(const CandyBar& cb) {
    std::cout << "Brand: " << cb.brd << std::endl;
    std::cout << "Weight: " << cb.wgt << std::endl;
    std::cout << "Calories: " << cb.cal << std::endl;
}

int main() {
    CandyBar cb1,cb2;

    set(cb1);
    std::cout << "CandyBar 1:" << std::endl;
    sh(cb1);
    
    set(cb2,"Choco Blast",3.5,400);
    std::cout << "\nCandyBar 2:" << std::endl;
    sh(cb2);
    
    return 0;
}
