#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    cin >> n;

    int count = 0;

    while (n > 0) {
        count += n & 1U;
        n >>= 1;
    }

    cout << "Set bits: " << count << endl;
    return 0;
}