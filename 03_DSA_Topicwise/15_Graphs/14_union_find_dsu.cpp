#include <iostream>
#include <vector>
using namespace std;

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

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    int a, b;
    cin >> a >> b;

    cout << (dsu.connected(a, b)
        ? "Connected"
        : "Not connected") << endl;

    return 0;
}