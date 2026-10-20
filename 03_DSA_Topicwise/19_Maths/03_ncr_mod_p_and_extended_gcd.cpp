#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

ll extendedGCD(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

ll modInverse(ll a, ll mod) {
    ll x, y;
    ll g = extendedGCD(a, mod, x, y);

    if (g != 1)
        return -1;

    return (x % mod + mod) % mod;
}

ll nCrMod(ll n, ll r, ll mod) {
    if (r < 0 || r > n)
        return 0;

    if (n >= mod) {
        cout << "Require n < mod for this implementation\n";
        return -1;
    }

    vector<ll> fact(n + 1, 1);

    for (ll i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % mod;

    ll denominator =
        fact[r] * fact[n - r] % mod;

    ll inverse = modInverse(denominator, mod);

    if (inverse == -1)
        return -1;

    return fact[n] * inverse % mod;
}

int main() {
    ll n, r, mod;
    cin >> n >> r >> mod;

    if (n < 0 || mod <= 1) {
        cout << "Invalid input\n";
        return 0;
    }

    ll x, y;

    ll g = extendedGCD(n, r, x, y);

    cout << "GCD: " << g << endl;
    cout << "nCr modulo p: "<< nCrMod(n, r, mod) << endl;

    return 0;
}