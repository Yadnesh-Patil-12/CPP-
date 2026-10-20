#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    priority_queue<pair<long long, int>> pq;

    for (int i = 0; i < (int)points.size(); i++) {
        long long d = 1LL * points[i][0] * points[i][0]
                    + 1LL * points[i][1] * points[i][1];

        pq.push({d, i});

        if ((int)pq.size() > k)
            pq.pop();
    }

    vector<vector<int>> ans;

    while (!pq.empty()) {
        ans.push_back(points[pq.top().second]);
        pq.pop();
    }

    return ans;
}

int main() {
    int n, k;
    cin >> n;

    vector<vector<int>> points(n, vector<int>(2));

    for (int i = 0; i < n; i++)
        cin >> points[i][0] >> points[i][1];

    cin >> k;

    if (k < 0 || k > n) {
        cout << "Invalid k\n";
        return 0;
    }

    vector<vector<int>> ans = kClosest(points, k);

    cout << "Closest points:\n";

    for (auto& p : ans)
        cout << p[0] << " " << p[1] << endl;

    return 0;
}