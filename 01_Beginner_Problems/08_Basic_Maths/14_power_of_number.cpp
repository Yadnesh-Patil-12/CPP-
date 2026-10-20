#include <iostream>
using namespace std;

int main() {
    double base;
    int exponent;

    cout << "Enter base and integer exponent: ";
    cin >> base >> exponent;

    if (base == 0 && exponent < 0) {
        cout << "Undefined: zero cannot have a negative exponent."
             << endl;
        return 0;
    }

    long long exp = exponent;
    bool negativeExponent = (exp < 0);

    if (negativeExponent)
        exp = -exp;

    double result = 1;
    double current = base;

    while (exp > 0) {
        if (exp % 2 == 1)
            result *= current;

        current *= current;
        exp /= 2;
    }

    if (negativeExponent)
        result = 1.0 / result;

    cout << "Result = " << result << endl;
    return 0;
}