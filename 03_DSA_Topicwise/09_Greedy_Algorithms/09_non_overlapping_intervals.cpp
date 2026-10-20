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

    sort(intervals.begin(), intervals.end(),
         [](const pair<int, int>& a,
            const pair<int, int>& b) {
             return a.second < b.second;
         });

    int removed = 0;
    int lastEnd = 0;
    bool first = true;

    for (const auto& interval : intervals) {
        if (first || interval.first >= lastEnd) {
            lastEnd = interval.second;
            first = false;
        } else {
            removed++;
        }
    }

    cout << "Minimum intervals to remove: "
         << removed << endl;

    return 0;
}