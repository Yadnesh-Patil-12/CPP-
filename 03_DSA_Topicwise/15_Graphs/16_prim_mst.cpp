#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    if (n == 0) {
        cout << "Empty graph\n";
        return 0;
    }

    vector<bool> visited(n, false);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    pq.push({0, 0});

    long long total = 0;
    int count = 0;

    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        total += weight;
        count++;

        for (auto [v, w] : adj[u]) {
            if (!visited[v])
                pq.push({w, v});
        }
    }

    if (count != n) {
        cout << "Graph is disconnected; no spanning tree exists.\n";
    } else {
        cout << "MST cost: " << total << endl;
    }

    return 0;
}