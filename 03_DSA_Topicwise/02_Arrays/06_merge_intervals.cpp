#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> intervals(n);

    for (int i = 0; i < n; i++)
        cin >> intervals[i].first >> intervals[i].second;

    if (n == 0) return 0;

    sort(intervals.begin(), intervals.end());

    vector<pair<int, int>> merged;

    for (auto interval : intervals) {
        if (merged.empty() ||
            interval.first > merged.back().second) {
            merged.push_back(interval);
        } else {
            merged.back().second =
                max(merged.back().second, interval.second);
        }
    }

    for (auto interval : merged)
        cout << "[" << interval.first << ", "
             << interval.second << "]" << endl;

    return 0;
}