#include <iostream>
#include <stdexcept>
using namespace std;

double divide(double a, double b) {
    if (b == 0)
        throw runtime_error("Division by zero is not allowed");

    return a / b;
}

int main() {
    double a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    try {
        cout << "Result: " << divide(a, b) << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}