#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    long long x = n;
    if (x < 0) x = -x;

    int count = 0;

    do {
        count++;
        x /= 10;
    } while (x != 0);

    cout << "Number of digits: " << count << endl;
    return 0;
}