#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 0 || n > 10000000) {
        cout << "Enter n between 0 and 10000000." << endl;
        return 0;
    }

    vector<int> bits(n + 1, 0);

    for (int i = 1; i <= n; i++)
        bits[i] = bits[i >> 1] + (i & 1);

    for (int i = 0; i <= n; i++)
        cout << i << ": " << bits[i] << " set bits" << endl;

    return 0;
}