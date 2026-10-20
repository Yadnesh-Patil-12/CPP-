#include <iostream>
using namespace std;

unsigned long long factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    cout << "Enter n (0 to 20): ";
    cin >> n;

    if (n < 0 || n > 20) {
        cout << "Invalid input." << endl;
        return 0;
    }

    cout << "Factorial = " << factorial(n) << endl;
    return 0;
}