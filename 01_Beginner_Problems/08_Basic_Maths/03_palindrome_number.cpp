#include <iostream>
using namespace std;

int main() {
    long long n, original, reverse = 0;

    cout << "Enter a number: ";
    cin >> n;

    original = n;

    if (n < 0) {
        cout << "Not a palindrome" << endl;
        return 0;
    }

    long long temp = n;

    while (temp != 0) {
        int digit = temp % 10;
        reverse = reverse * 10 + digit;
        temp /= 10;
    }

    if (original == reverse)
        cout << "Palindrome number" << endl;
    else
        cout << "Not a palindrome" << endl;

    return 0;
}