#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {40, 10, 30, 20, 50};

    sort(v.begin(), v.end());

    cout << "Sorted: ";
    for (int x : v) {
        cout << x << " ";
    }

    cout << "\nBinary search for 30: "
         << (binary_search(v.begin(), v.end(), 30) ? "Found" : "Not found");

    cout << "\nMinimum: " << *min_element(v.begin(), v.end());
    cout << "\nMaximum: " << *max_element(v.begin(), v.end());

    reverse(v.begin(), v.end());

    cout << "\nReversed: ";
    for (int x : v) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}