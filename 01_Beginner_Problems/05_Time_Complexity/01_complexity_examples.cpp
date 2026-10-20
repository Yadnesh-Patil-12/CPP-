#include <iostream>
using namespace std;

// O(1) - Constant time
void constantTime(int n) {
    cout << "Number: " << n << endl;
}

// O(n) - Linear time
void linearTime(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// O(n^2) - Quadratic time
void quadraticTime(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "(" << i << "," << j << ") ";
        }
        cout << endl;
    }
}

int main() {
    int n = 3;

    cout << "O(1) Complexity:" << endl;
    constantTime(n);

    cout << "\nO(n) Complexity:" << endl;
    linearTime(n);

    cout << "\nO(n^2) Complexity:" << endl;
    quadraticTime(n);

    return 0;
}