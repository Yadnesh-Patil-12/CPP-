#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (a[mid] == 0) {
            swap(a[low], a[mid]);
            low++;
            mid++;
        } else if (a[mid] == 1) {
            mid++;
        } else if (a[mid] == 2) {
            swap(a[mid], a[high]);
            high--;
        } else {
            cout << "Invalid input: use only 0, 1, and 2."
                 << endl;
            return 0;
        }
    }

    for (int x : a)
        cout << x << " ";

    cout << endl;
    return 0;
}