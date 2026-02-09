#include <iostream>
#include <cstring>
using namespace std;

struct customer {
    char name[35];
    double pay;
};

class Stack {
private:
    enum { MAX=10 };
    customer items[MAX];
    int top;
public:
    Stack() { top=0; }
    bool isempty() const { return top==0; }
    bool isfull() const { return top==MAX; }
    bool push(const customer & c) {
        if (top<MAX) {
            items[top]=c;
            top++;
            return true;
        }
        return false;
    }
    bool pop(customer & c) {
        if(top>0) {
            c=items[--top];
            return true;
        }
        return false;
    }
};

int main() {
    Stack st;
    customer c;
    double total = 0;
    int n;

    cout << "输入顾客数: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; ++i) {
        cout << "姓名: ";
        cin.getline(c.name, 35);
        cout << "支付额: ";
        cin >> c.pay;
        cin.ignore();
        if (!st.push(c)) {
            cout << "栈满!\n";
            break;
        }
    }

    while (st.pop(c)) {
        total += c.pay;
        cout << c.name << " 支付 " << c.pay << ", 当前总计: " << total << endl;
    }

    cout << "最终总计: " << total << endl;
    return 0;
}
