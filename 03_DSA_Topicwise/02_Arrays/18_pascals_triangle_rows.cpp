#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<vector<long long>> triangle;

    for (int i = 0; i < n; i++) {
        vector<long long> row(i + 1, 1);

        for (int j = 1; j < i; j++)
            row[j] = triangle[i - 1][j - 1]
                   + triangle[i - 1][j];

        triangle.push_back(row);
    }

    for (const auto& row : triangle) {
        for (long long x : row)
            cout << x << " ";
        cout << endl;
    }

    return 0;
}