#include <iostream>
#include <cstring>
#include <new>

struct chaff {
    char dross[20];
    int slag;
};

int main()
{
    const int size=512;
    char buffer[size];

    chaff *p=new (buffer) chaff[2];

    strcpy(p[0].dross,"First Chaff");
    p[0].slag=10;

    strcpy(p[1].dross,"Second Chaff");
    p[1].slag=20;
    int i;
    for(i=0;i<2;i++) {
        std::cout << "Chaff " << i + 1 << ": " << std::endl;
        std::cout << "Dross: " << p[i].dross << std::endl;
        std::cout << "Slag: " << p[i].slag << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
