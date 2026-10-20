#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool isPrime = (n >= 2);

    for (int i = 2; isPrime && i <= n / i; i++) {
        if (n % i == 0)
            isPrime = false;
    }

    if (isPrime)
        cout << "Prime number" << endl;
    else
        cout << "Not a prime number" << endl;

    return 0;
}