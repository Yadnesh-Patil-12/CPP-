#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>>& adj,
         vector<bool>& visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, adj, visited);
    }
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
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << "Connected components: "
         << components << endl;

    return 0;
}