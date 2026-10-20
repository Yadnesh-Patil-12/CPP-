#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int position = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0)
            arr[position++] = arr[i];
    }

    while (position < n)
        arr[position++] = 0;

    for (int x : arr)
        cout << x << " ";

    cout << endl;
    return 0;
}