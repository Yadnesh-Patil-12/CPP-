#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n > 0 && (n & (n - 1)) == 0)
        cout << "Power of two" << endl;
    else
        cout << "Not a power of two" << endl;

    return 0;
}