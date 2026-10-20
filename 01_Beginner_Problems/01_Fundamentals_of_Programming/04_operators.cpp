#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 3;

    cout << "Addition: " << a + b << endl;
    cout << "Subtraction: " << a - b << endl;
    cout << "Multiplication: " << a * b << endl;
    cout << "Division: " << a / b << endl;
    cout << "Remainder: " << a % b << endl;

    cout << "Greater than: " << (a > b) << endl;
    cout << "Equal to: " << (a == b) << endl;
    cout << "Logical AND: " << (a > 5 && b < 5) << endl;

    return 0;
}