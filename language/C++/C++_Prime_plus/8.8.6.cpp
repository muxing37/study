#include <iostream>
#include <cstring>

template <typename T>
T maxn(T arr[],int n) {
    T max=arr[0];
    int i;
    for(i=1;i<n;i++) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}

template <>
const char* maxn<const char*>(const char* arr[],int n) {
    const char* longest=arr[0];
    int i;
    for(i=1;i<n;i++) {
        if(strlen(arr[i])>strlen(longest)) {
            longest=arr[i];
        }
    }
    return longest;
}

int main() {
    int iarr[6]={1,5,3,9,2,8};
    std::cout << "Max int: " << maxn(iarr, 6) << std::endl;
    
    double darr[4]={1.2,3.4,5.6,4.5};
    std::cout << "Max double: " << maxn(darr, 4) << std::endl;
    
    const char* sarr[5]= {
        "Hello",
        "World",
        "C++ Programming",
        "Template",
        "Function"
    };
    std::cout << "Longest string: " << maxn(sarr, 5) << std::endl;
    
    return 0;
}
