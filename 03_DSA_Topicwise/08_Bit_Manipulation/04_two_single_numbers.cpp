#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int xorAll = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        xorAll ^= a[i];
    }

    if (xorAll == 0) {
        cout << "Invalid input or no distinct pair" << endl;
        return 0;
    }

    unsigned int diffBit =
        static_cast<unsigned int>(xorAll) &
        (0U - static_cast<unsigned int>(xorAll));

    int first = 0, second = 0;

    for (int x : a) {
        if (static_cast<unsigned int>(x) & diffBit)
            first ^= x;
        else
            second ^= x;
    }

    cout << "Single numbers: " << first
         << " " << second << endl;

    return 0;
}