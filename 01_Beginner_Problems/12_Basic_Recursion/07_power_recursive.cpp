#include <iostream>
using namespace std;

double power(double base, long long exponent) {
    if (exponent == 0) return 1;

    double half = power(base, exponent / 2);
    double result = half * half;

    if (exponent % 2 != 0)
        result *= base;

    return result;
}

int main() {
    double base;
    long long exponent;

    cout << "Enter base and exponent: ";
    cin >> base >> exponent;

    if (base == 0 && exponent < 0) {
        cout << "Undefined result." << endl;
        return 0;
    }

    long long positiveExponent = exponent;

    if (positiveExponent < 0)
        positiveExponent = -positiveExponent;

    double result = power(base, positiveExponent);

    if (exponent < 0)
        result = 1.0 / result;

    cout << "Result = " << result << endl;
    return 0;
}