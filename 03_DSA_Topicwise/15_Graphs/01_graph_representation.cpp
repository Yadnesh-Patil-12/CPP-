#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n);
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    cout << "Adjacency List:\n";

    for (int i = 0; i < n; i++) {
        cout << i << ": ";

        for (int v : adj[i])
            cout << v << " ";

        cout << endl;
    }

    cout << "\nAdjacency Matrix:\n";

    for (auto& row : matrix) {
        for (int x : row)
            cout << x << " ";

        cout << endl;
    }

    return 0;
}