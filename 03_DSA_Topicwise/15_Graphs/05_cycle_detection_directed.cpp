#include <iostream>
#include <vector>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj,
         vector<int>& state) {
    state[u] = 1;

    for (int v : adj[u]) {
        if (state[v] == 1)
            return true;

        if (state[v] == 0 && dfs(v, adj, state))
            return true;
    }

    state[u] = 2;
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
    }

    vector<int> state(n, 0);
    bool cycle = false;

    for (int i = 0; i < n; i++) {
        if (state[i] == 0 && dfs(i, adj, state)) {
            cycle = true;
            break;
        }
    }

    cout << (cycle ? "Cycle detected" : "No cycle") << endl;

    return 0;
}