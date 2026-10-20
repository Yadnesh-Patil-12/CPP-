#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int candidate = 0;
    int count = 0;

    for (int x : a) {
        if (count == 0)
            candidate = x;

        if (x == candidate)
            count++;
        else
            count--;
    }

    count = 0;

    for (int x : a) {
        if (x == candidate)
            count++;
    }

    if (count > n / 2)
        cout << "Majority element: " << candidate << endl;
    else
        cout << "No majority element" << endl;

    return 0;
}