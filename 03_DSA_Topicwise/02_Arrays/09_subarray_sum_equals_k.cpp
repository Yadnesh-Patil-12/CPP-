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

    long long k;
    cin >> k;

    unordered_map<long long, long long> prefixCount;
    prefixCount[0] = 1;

    long long prefixSum = 0;
    long long total = 0;

    for (int x : a) {
        prefixSum += x;

        if (prefixCount.count(prefixSum - k))
            total += prefixCount[prefixSum - k];

        prefixCount[prefixSum]++;
    }

    cout << "Number of subarrays: " << total << endl;
    return 0;
}