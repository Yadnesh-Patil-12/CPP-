#include <iostream>
using namespace std;

int main() {
    int a, b, n;

    cout << "Enter two numbers to swap: ";
    cin >> a >> b;

    if (&a != &b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }

    cout << "After swap: " << a << " " << b << endl;

    cout << "Enter a number to check odd/even: ";
    cin >> n;

    if (n & 1)
        cout << "Odd number" << endl;
    else
        cout << "Even number" << endl;

    return 0;
}