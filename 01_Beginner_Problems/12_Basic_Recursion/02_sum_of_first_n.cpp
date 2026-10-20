#include <iostream>
using namespace std;

long long sum(int n) {
    if (n <= 0) return 0;
    return n + sum(n - 1);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n < 0) {
        cout << "Enter a non-negative number." << endl;
        return 0;
    }

    cout << "Sum = " << sum(n) << endl;
    return 0;
}