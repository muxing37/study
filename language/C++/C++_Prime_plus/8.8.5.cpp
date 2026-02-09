#include <iostream>

template <typename T>
T max5(T arr[5]) {
	int i; 
    T max=arr[0];
    for(i=1;i<5;i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}

int main() {
    int iarr[5]={1,5,3,9,2};
    double darr[5]={1.2,3.4,5.6,7.8,4.5};

    std::cout << "Max int: " << max5(iarr) << std::endl;
    std::cout << "Max double: " << max5(darr) << std::endl;

    return 0;
}
