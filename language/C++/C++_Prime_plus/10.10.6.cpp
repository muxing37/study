#include <iostream>
using namespace std;

class Move {
private:
    double x;
    double y;
public:
    Move(double a=0,double b=0) : x(a), y(b) {}
    void show() const { cout << "(" << x << ", " << y << ")\n"; }
    Move add(const Move & m) const {
        return Move(x+m.x,y+m.y);
    }
    void reset(double a=0,double b=0) {
        x=a;
        y=b;
    }
};

int main() {
    Move m1(2.5,3.8);
    Move m2(1.2,4.7);

    cout << "m1: ";
    m1.show();
    cout << "m2: ";
    m2.show();

    Move m3 = m1.add(m2);
    cout << "m1 + m2: ";
    m3.show();

    m1.reset();
    cout << "m1 after reset: ";
    m1.show();

    m2.reset(5.5, 6.6);
    cout << "m2 after reset(5.5, 6.6): ";
    m2.show();

    return 0;
}
