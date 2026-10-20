#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cin >> k;

    k = ((k % n) + n) % n;

    // Rotate right by k positions
    reverse(arr.begin(), arr.end());
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());

    for (int x : arr)
        cout << x << " ";

    cout << endl;
    return 0;
}