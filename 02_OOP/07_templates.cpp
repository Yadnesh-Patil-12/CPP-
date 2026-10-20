#include <iostream>
using namespace std;

template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    cout << "Maximum integer: "
         << findMax(10, 20) << endl;

    cout << "Maximum double: "
         << findMax(3.5, 2.5) << endl;

    int a = 5, b = 10;

    swapValues(a, b);

    cout << "After swap: " << a << " " << b << endl;

    return 0;
}