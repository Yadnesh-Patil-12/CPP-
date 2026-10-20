#include <iostream>
#include <climits>
using namespace std;

int main() {
    cout << "Maximum int: " << INT_MAX << endl;
    cout << "Minimum int: " << INT_MIN << endl;

    int a = 17, b = 5;

    cout << "\n17 / 5 = " << a / b << endl;
    cout << "17 % 5 = " << a % b << endl;

    int x = -17;

    cout << "-17 % 5 = " << x % b << endl;

    cout << "\nInteger overflow can cause undefined behavior "
         << "in C++ for signed integers." << endl;

    return 0;
}