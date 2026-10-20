#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }

    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;

    if (sr < 0 || sr >= rows ||
        sc < 0 || sc >= cols ||
        er < 0 || er >= rows ||
        ec < 0 || ec >= cols ||
        grid[sr][sc] == 0 ||
        grid[er][ec] == 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> dist(
        rows, vector<int>(cols, -1)
    );

    queue<pair<int, int>> q;

    q.push({sr, sc});
    dist[sr][sc] = 0;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        if (r == er && c == ec) {
            cout << dist[r][c] << endl;
            return 0;
        }

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                grid[nr][nc] == 1 &&
                dist[nr][nc] == -1) {

                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    cout << -1 << endl;

    return 0;
}