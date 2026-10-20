#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<int>> grid(rows, vector<int>(cols));
    queue<pair<int, int>> q;

    int fresh = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 2)
                q.push({i, j});
            else if (grid[i][j] == 1)
                fresh++;
        }
    }

    int minutes = 0;
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty() && fresh > 0) {
        int size = q.size();
        minutes++;

        while (size--) {
            auto [r, c] = q.front();
            q.pop();

            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];

                if (nr >= 0 && nc >= 0 &&
                    nr < rows && nc < cols &&
                    grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }
    }

    cout << (fresh == 0 ? minutes : -1) << endl;

    return 0;
}