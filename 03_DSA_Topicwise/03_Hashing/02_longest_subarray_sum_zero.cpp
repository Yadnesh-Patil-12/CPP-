#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    unordered_map<long long, int> firstIndex;
    firstIndex[0] = -1;

    long long prefixSum = 0;
    int longest = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += a[i];

        if (firstIndex.count(prefixSum)) {
            longest = max(longest, i - firstIndex[prefixSum]);
        } else {
            firstIndex[prefixSum] = i;
        }
    }

    cout << "Longest zero-sum subarray: " << longest << endl;
    return 0;
}