#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool searchWord(vector<vector<char>>& board,
                const string& word, int row, int col,
                int index) {
    if (index == (int)word.size())
        return true;

    int m = board.size();
    int n = board[0].size();

    if (row < 0 || row >= m || col < 0 || col >= n)
        return false;

    if (board[row][col] != word[index])
        return false;

    char original = board[row][col];
    board[row][col] = '#';

    bool found =
        searchWord(board, word, row + 1, col, index + 1) ||
        searchWord(board, word, row - 1, col, index + 1) ||
        searchWord(board, word, row, col + 1, index + 1) ||
        searchWord(board, word, row, col - 1, index + 1);

    board[row][col] = original;

    return found;
}

int main() {
    int m, n;
    cin >> m >> n;

    if (m <= 0 || n <= 0)
        return 0;

    vector<vector<char>> board(m, vector<char>(n));

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> board[i][j];

    string word;
    cin >> word;

    if (word.empty()) {
        cout << "Word found" << endl;
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (searchWord(board, word, i, j, 0)) {
                cout << "Word found" << endl;
                return 0;
            }
        }
    }

    cout << "Word not found" << endl;
    return 0;
}