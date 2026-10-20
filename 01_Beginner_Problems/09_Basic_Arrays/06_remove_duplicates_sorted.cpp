#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Input array must be sorted
    int k = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[k++] = arr[i];
        }
    }

    cout << "Unique elements: ";

    for (int i = 0; i < k; i++)
        cout << arr[i] << " ";

    cout << "\nCount: " << k << endl;
    return 0;
}