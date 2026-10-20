#include <iostream>
using namespace std;

int main() {
    int x = 10;

    int* ptr = &x;
    int& ref = x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Pointer stores address: " << ptr << endl;
    cout << "Value using pointer: " << *ptr << endl;
    cout << "Value using reference: " << ref << endl;

    *ptr = 20;

    cout << "\nAfter changing through pointer: " << x << endl;

    ref = 30;

    cout << "After changing through reference: " << x << endl;

    return 0;
}