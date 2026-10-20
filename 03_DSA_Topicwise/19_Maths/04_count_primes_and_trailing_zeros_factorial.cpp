#include <iostream>
#include <vector>
using namespace std;

int countPrimes(int n) {
    if (n <= 2)
        return 0;

    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; 1LL * i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }

    int count = 0;

    for (int i = 2; i < n; i++) {
        if (isPrime[i])
            count++;
    }

    return count;
}

long long trailingZeros(long long n) {
    long long count = 0;

    while (n > 0) {
        n /= 5;
        count += n;
    }

    return count;
}

int main() {
    int n;
    long long factorialN;

    cin >> n >> factorialN;

    if (n < 0 || factorialN < 0) {
        cout << "Invalid input\n";
        return 0;
    }

    cout << "Count of primes less than n: "<< countPrimes(n) << endl;

    cout << "Trailing zeros in factorial: "<< trailingZeros(factorialN) << endl;

    return 0;
}