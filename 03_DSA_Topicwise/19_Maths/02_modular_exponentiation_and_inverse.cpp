#include <iostream>
using namespace std;

using ll = long long;

ll modPow(ll a, ll b, ll mod) {
    ll result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1)
            result = result * a % mod;

        a = a * a % mod;
        b >>= 1;
    }

    return result;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

int main() {
    ll a, b, mod;
    cin >> a >> b >> mod;

    if (mod <= 1 || b < 0) {
        cout << "Invalid input\n";
        return 0;
    }

    cout << "Power: " << modPow(a, b, mod) << endl;

    if (gcd(a, mod) == 1) {
        cout << "Modular inverse: "<< modPow((a % mod + mod) % mod,mod - 2, mod)<< endl;
        cout << "(Inverse formula assumes a prime modulus.)\n";
    } else {
        cout << "Modular inverse does not exist\n";
    }

    return 0;
}