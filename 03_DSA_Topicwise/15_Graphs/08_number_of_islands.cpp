#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, vector<vector<char>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (r < 0 || c < 0 || r >= rows || c >= cols ||
        grid[r][c] != '1')
        return;

    grid[r][c] = '0';

    dfs(r + 1, c, grid);
    dfs(r - 1, c, grid);
    dfs(r, c + 1, grid);
    dfs(r, c - 1, grid);
}

int main() {
    int rows, cols;
    cin >> rows >> cols;

    vector<vector<char>> grid(rows, vector<char>(cols));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> grid[i][j];

    int islands = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '1') {
                islands++;
                dfs(i, j, grid);
            }
        }
    }

    cout << "Number of islands: " << islands << endl;

    return 0;
}