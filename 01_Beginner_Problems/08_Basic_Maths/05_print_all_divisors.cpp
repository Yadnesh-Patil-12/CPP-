#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;

    if (n <= 0) {
        cout << "Please enter a positive number." << endl;
        return 0;
    }

    cout << "Divisors: ";

    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            cout << i << " ";

            int other = n / i;
            if (other != i)
                cout << other << " ";
        }
    }

    cout << endl;
    return 0;
}