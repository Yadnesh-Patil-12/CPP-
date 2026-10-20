#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    if (m <= 0 || n <= 0) return 0;

    vector<vector<int>> a(m, vector<int>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    bool firstRow = false, firstCol = false;

    for (int j = 0; j < n; j++)
        if (a[0][j] == 0) firstRow = true;

    for (int i = 0; i < m; i++)
        if (a[i][0] == 0) firstCol = true;

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (a[i][j] == 0) {
                a[i][0] = 0;
                a[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (a[i][0] == 0 || a[0][j] == 0)
                a[i][j] = 0;

    if (firstRow)
        for (int j = 0; j < n; j++)
            a[0][j] = 0;

    if (firstCol)
        for (int i = 0; i < m; i++)
            a[i][0] = 0;

    for (const auto& row : a) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }

    return 0;
}