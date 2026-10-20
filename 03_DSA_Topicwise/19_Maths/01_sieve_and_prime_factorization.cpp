#include <iostream>
#include <vector>
using namespace std;

vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);

    if (n >= 0)
        isPrime[0] = false;

    if (n >= 1)
        isPrime[1] = false;

    for (int i = 2; 1LL * i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    return isPrime;
}

void primeFactorization(int n) {
    if (n < 2) {
        cout << "No prime factors\n";
        return;
    }

    for (int i = 2; 1LL * i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }

    if (n > 1)
        cout << n;

    cout << endl;
}

int main() {
    int limit;
    cin >> limit;

    if (limit < 0) {
        cout << "Invalid limit\n";
        return 0;
    }

    vector<bool> isPrime = sieve(limit);

    cout << "Prime numbers: ";

    for (int i = 2; i <= limit; i++) {
        if (isPrime[i])
            cout << i << " ";
    }

    cout << "\nEnter number for prime factorization: ";

    int n;
    cin >> n;

    primeFactorization(n);

    return 0;
}