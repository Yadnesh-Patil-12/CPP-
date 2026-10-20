#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 2) {
        cout << "Second largest does not exist" << endl;
        return 0;
    }

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int largest = INT_MIN;
    int second = INT_MIN;

    for (int x : arr) {
        if (x > largest) {
            second = largest;
            largest = x;
        } else if (x < largest && x > second) {
            second = x;
        }
    }

    if (second == INT_MIN)
        cout << "Second largest does not exist" << endl;
    else
        cout << "Second largest: " << second << endl;

    return 0;
}