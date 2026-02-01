#include <iostream>
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};
void sh(const box b) {
    std::cout << "Maker: " << b.maker << std::endl;
    std::cout << "Height: " << b.height << std::endl;
    std::cout << "Width: " << b.width << std::endl;
    std::cout << "Length: " << b.length << std::endl;
    std::cout << "Volume: " << b.volume << std::endl;
}
void sv(box* b) {
    b->volume=b->height*b->width*b->length;
}
int main() {
    box bx = {"Best Box",10.0,12.0,5.0,0.0};
    std::cout << "Original box data:" << std::endl;
    sh(bx);
    sv(&bx);
    std::cout << "\nAfter setting volume:" << std::endl;
    sh(bx);
    return 0;
}