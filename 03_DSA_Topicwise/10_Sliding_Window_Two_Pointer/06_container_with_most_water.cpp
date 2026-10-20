#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        cin >> height[i];

        if (height[i] < 0) {
            cout << "Heights cannot be negative." << endl;
            return 0;
        }
    }

    int left = 0;
    int right = n - 1;

    long long maxArea = 0;

    while (left < right) {
        long long area = 1LL *
            min(height[left], height[right]) *
            (right - left);

        maxArea = max(maxArea, area);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    cout << "Maximum water area: " << maxArea << endl;

    return 0;
}