#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> activities(n);

    for (int i = 0; i < n; i++)
        cin >> activities[i].first >> activities[i].second;

    sort(activities.begin(), activities.end(),
         [](const pair<int, int>& a,
            const pair<int, int>& b) {
             return a.second < b.second;
         });

    int count = 0;
    int lastEnd = 0;
    bool first = true;

    cout << "Selected activities:" << endl;

    for (auto activity : activities) {
        if (first || activity.first >= lastEnd) {
            cout << activity.first << " "
                 << activity.second << endl;

            lastEnd = activity.second;
            first = false;
            count++;
        }
    }

    cout << "Maximum activities: " << count << endl;
    return 0;
}