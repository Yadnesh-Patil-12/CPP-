#include <iostream>
using namespace std;

int main() {
    long long a, b;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b != 0) {
        long long remainder = a % b;
        a = b;
        b = remainder;
    }

    cout << "GCD = " << a << endl;
    return 0;
}