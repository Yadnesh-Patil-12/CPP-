#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of terms (1 to 93): ";
    cin >> n;

    if (n < 1 || n > 93) {
        cout << "Invalid number of terms." << endl;
        return 0;
    }

    unsigned long long a = 0, b = 1;

    cout << "Fibonacci series: ";

    for (int i = 0; i < n; i++) {
        cout << a << " ";

        unsigned long long next = a + b;
        a = b;
        b = next;
    }

    cout << endl;
    return 0;
}