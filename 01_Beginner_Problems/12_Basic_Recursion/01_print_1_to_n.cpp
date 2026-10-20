#include <iostream>
using namespace std;

void printNumbers(int n) {
    if (n == 0) return;

    printNumbers(n - 1);
    cout << n << " ";
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    if (n >= 1)
        printNumbers(n);

    cout << endl;
    return 0;
}