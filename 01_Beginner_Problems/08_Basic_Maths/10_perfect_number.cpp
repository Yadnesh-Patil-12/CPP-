#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a positive number: ";
    cin >> n;

    if (n <= 1) {
        cout << "Not a perfect number" << endl;
        return 0;
    }

    int sum = 1;

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            sum += i;

            if (i != n / i)
                sum += n / i;
        }
    }

    if (sum == n)
        cout << "Perfect number" << endl;
    else
        cout << "Not a perfect number" << endl;

    return 0;
}