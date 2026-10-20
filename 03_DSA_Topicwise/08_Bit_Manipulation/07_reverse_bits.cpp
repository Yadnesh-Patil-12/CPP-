#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uint32_t n;
    cin >> n;

    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1U);
        n >>= 1;
    }

    cout << "Reversed bits: " << result << endl;
    return 0;
}