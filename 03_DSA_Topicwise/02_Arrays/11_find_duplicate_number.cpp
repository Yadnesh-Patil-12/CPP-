#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) return 0;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    // Assumption: values are in the range 1 to n-1,
    // and at least one value is duplicated.
    int slow = a[0];
    int fast = a[0];

    do {
        slow = a[slow];
        fast = a[a[fast]];
    } while (slow != fast);

    slow = a[0];

    while (slow != fast) {
        slow = a[slow];
        fast = a[fast];
    }

    cout << "Duplicate number: " << slow << endl;
    return 0;
}