#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    v.push_back(50);

    cout << "Vector elements: ";
    for (int x : v) {
        cout << x << " ";
    }

    cout << "\nSize: " << v.size() << endl;

    v.pop_back();

    cout << "After pop_back: ";
    for (int x : v) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}