#include <iostream>
using namespace std;

int main() {
    long long a, b;

    cout << "Enter two positive numbers: ";
    cin >> a >> b;

    if (a <= 0 || b <= 0) {
        cout << "Please enter positive numbers." << endl;
        return 0;
    }

    long long x = a, y = b;

    while (y != 0) {
        long long remainder = x % y;
        x = y;
        y = remainder;
    }

    long long gcd = x;

    cout << "LCM = " << (a / gcd) * b << endl;
    return 0;
}