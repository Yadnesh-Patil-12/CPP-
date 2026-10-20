#include <iostream>
using namespace std;

int main() {
    unsigned int n;
    int position;

    cout << "Enter number and bit position: ";
    cin >> n >> position;

    if (position < 0 || position >= 32) {
        cout << "Invalid bit position" << endl;
        return 0;
    }

    unsigned int mask = 1U << position;

    cout << "Get bit: " << ((n & mask) != 0) << endl;
    cout << "Set bit: " << (n | mask) << endl;
    cout << "Clear bit: " << (n & ~mask) << endl;
    cout << "Toggle bit: " << (n ^ mask) << endl;

    return 0;
}