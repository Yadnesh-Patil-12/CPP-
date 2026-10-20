#include <iostream>
#include <vector>
using namespace std;

void reverseArray(vector<int>& arr, int left, int right) {
    if (left >= right) return;

    swap(arr[left], arr[right]);

    reverseArray(arr, left + 1, right - 1);
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    if (n < 0) return 0;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    if (n > 0)
        reverseArray(arr, 0, n - 1);

    cout << "Reversed array: ";

    for (int x : arr)
        cout << x << " ";

    cout << endl;
    return 0;
}