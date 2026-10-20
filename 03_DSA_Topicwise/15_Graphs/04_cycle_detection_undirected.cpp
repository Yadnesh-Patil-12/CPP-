#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, int parent, vector<vector<int>>& adj,
         vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (dfs(v, u, adj, visited))
                return true;
        } else if (v != parent) {
            return true;
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n, false);
    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dfs(i, -1, adj, visited)) {
            cycle = true;
            break;
        }
    }

    cout << (cycle ? "Cycle detected" : "No cycle") << endl;

    return 0;
}