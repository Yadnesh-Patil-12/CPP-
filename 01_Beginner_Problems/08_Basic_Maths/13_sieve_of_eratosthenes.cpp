#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Find primes up to: ";
    cin >> n;

    if (n < 2) {
        cout << "No prime numbers in this range." << endl;
        return 0;
    }

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n / i; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    cout << "Prime numbers: ";

    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }

    cout << endl;
    return 0;
}