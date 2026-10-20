#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> height(n);
    for (int i = 0; i < n; i++)
        cin >> height[i];

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    long long water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            leftMax = max(leftMax, height[left]);
            water += leftMax - height[left];
            left++;
        } else {
            rightMax = max(rightMax, height[right]);
            water += rightMax - height[right];
            right--;
        }
    }

    cout << "Trapped rain water: " << water << endl;
    return 0;
}