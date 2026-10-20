#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto& e : edges)
        cin >> e.u >> e.v >> e.w;

    int source;
    cin >> source;

    vector<long long> dist(n, LLONG_MAX);
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool changed = false;

        for (auto e : edges) {
            if (dist[e.u] != LLONG_MAX &&
                dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        }

        if (!changed) break;
    }

    for (auto e : edges) {
        if (dist[e.u] != LLONG_MAX &&
            dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative cycle detected\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        if (dist[i] == LLONG_MAX)
            cout << "Unreachable\n";
        else
            cout << dist[i] << endl;
    }

    return 0;
}