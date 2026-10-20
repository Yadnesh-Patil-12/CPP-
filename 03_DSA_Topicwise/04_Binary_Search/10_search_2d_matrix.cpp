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

    int target;
    cin >> target;

    int left = 0;
    int right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / cols;
        int col = mid % cols;

        if (a[row][col] == target) {
            cout << "Found at position: "
                 << row << ", " << col << endl;
            return 0;
        } else if (a[row][col] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << "Not found" << endl;
    return 0;
}