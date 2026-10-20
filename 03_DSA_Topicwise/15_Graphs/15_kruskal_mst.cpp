#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

class DSU {
    vector<int> parent, rankSize;

public:
    DSU(int n) {
        parent.resize(n);
        rankSize.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b) return false;

        if (rankSize[a] < rankSize[b])
            swap(a, b);

        parent[b] = a;

        if (rankSize[a] == rankSize[b])
            rankSize[a]++;

        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);

    for (auto& e : edges)
        cin >> e.u >> e.v >> e.w;

    sort(edges.begin(), edges.end(),
         [](Edge a, Edge b) {
             return a.w < b.w;
         });

    DSU dsu(n);
    long long total = 0;
    int count = 0;

    for (auto e : edges) {
        if (dsu.unite(e.u, e.v)) {
            cout << e.u << " - " << e.v
                 << " : " << e.w << endl;

            total += e.w;
            count++;
        }
    }

    if (count != n - 1) {
        cout << "Graph is disconnected; no spanning tree exists.\n";
    } else {
        cout << "MST cost: " << total << endl;
    }

    return 0;
}