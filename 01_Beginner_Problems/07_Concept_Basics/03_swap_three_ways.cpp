#include <iostream>
using namespace std;

void swapUsingTemp(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapUsingArithmetic(int& a, int& b) {
    if (a == b) return;

    a = a + b;
    b = a - b;
    a = a - b;
}

void swapUsingXOR(int& a, int& b) {
    if (&a == &b) return;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int main() {
    int a = 10, b = 20;

    cout << "Original: a = " << a << ", b = " << b << endl;

    swapUsingTemp(a, b);
    cout << "Using temp: a = " << a << ", b = " << b << endl;

    swapUsingArithmetic(a, b);
    cout << "Using arithmetic: a = " << a << ", b = " << b << endl;

    swapUsingXOR(a, b);
    cout << "Using XOR: a = " << a << ", b = " << b << endl;

    return 0;
}