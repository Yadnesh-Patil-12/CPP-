#include <iostream>
using namespace std;

int main() {
    long long n, reverse = 0;

    cout << "Enter a number: ";
    cin >> n;

    while (n != 0) {
        int digit = n % 10;
        reverse = reverse * 10 + digit;
        n /= 10;
    }

    cout << "Reversed number: " << reverse << endl;
    return 0;
}