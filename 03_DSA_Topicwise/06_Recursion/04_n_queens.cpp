#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int row, int n, vector<string>& board,
           vector<bool>& columns,
           vector<bool>& diagonal1,
           vector<bool>& diagonal2,
           int& solutions) {
    if (row == n) {
        solutions++;

        for (const string& line : board)
            cout << line << endl;

        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        int d1 = row - col + n - 1;
        int d2 = row + col;

        if (columns[col] || diagonal1[d1] || diagonal2[d2])
            continue;

        board[row][col] = 'Q';
        columns[col] = diagonal1[d1] = diagonal2[d2] = true;

        solve(row + 1, n, board, columns,
              diagonal1, diagonal2, solutions);

        board[row][col] = '.';
        columns[col] = diagonal1[d1] = diagonal2[d2] = false;
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 1 || n > 12) {
        cout << "Enter n between 1 and 12." << endl;
        return 0;
    }

    vector<string> board(n, string(n, '.'));
    vector<bool> columns(n, false);
    vector<bool> diagonal1(2 * n - 1, false);
    vector<bool> diagonal2(2 * n - 1, false);

    int solutions = 0;

    solve(0, n, board, columns,
          diagonal1, diagonal2, solutions);

    cout << "Total solutions: " << solutions << endl;

    return 0;
}