#include <iostream>
#include "stack.h"

int main() {
    Stack st;
    customer cust;
    double total=0.0;

    customer c1={"John Doe",100.0};
    customer c2={"Jane Smith",200.0};
    customer c3={"Bob Johnson",150.0};
    
    st.push(c1);
    st.push(c2);
    st.push(c3);

    while (!st.isempty()) {
        st.pop(cust);
        total += cust.payment;
        std::cout << "Customer: " << cust.fullname 
                  << ", Payment: " << cust.payment 
                  << ", Total so far: " << total << std::endl;
    }

    std::cout << "Total payment: " << total << std::endl;

    return 0;
}
