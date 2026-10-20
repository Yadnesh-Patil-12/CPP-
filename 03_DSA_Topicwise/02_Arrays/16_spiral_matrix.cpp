#include <iostream>
#include <vector>
using namespace std;

int main() {
    int rows, cols;
    cin >> rows >> cols;

    if (rows <= 0 || cols <= 0) return 0;

    vector<vector<int>> a(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> a[i][j];

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            cout << a[top][j] << " ";
        top++;

        for (int i = top; i <= bottom; i++)
            cout << a[i][right] << " ";
        right--;

        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                cout << a[bottom][j] << " ";
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                cout << a[i][left] << " ";
            left++;
        }
    }

    cout << endl;
    return 0;
}