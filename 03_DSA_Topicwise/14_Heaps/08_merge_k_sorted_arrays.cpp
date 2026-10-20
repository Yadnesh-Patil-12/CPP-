#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Element {
    int value, row, col;

    bool operator>(const Element& other) const {
        return value > other.value;
    }
};

vector<int> mergeKArrays(vector<vector<int>>& arrays) {
    priority_queue<Element, vector<Element>, greater<Element>> pq;

    for (int i = 0; i < (int)arrays.size(); i++) {
        if (!arrays[i].empty())
            pq.push({arrays[i][0], i, 0});
    }

    vector<int> result;

    while (!pq.empty()) {
        Element curr = pq.top();
        pq.pop();

        result.push_back(curr.value);

        int nextCol = curr.col + 1;

        if (nextCol < (int)arrays[curr.row].size()) {
            pq.push({
                arrays[curr.row][nextCol],
                curr.row,
                nextCol
            });
        }
    }

    return result;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>> arrays(k);

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        arrays[i].resize(n);

        for (int& x : arrays[i])
            cin >> x;
    }

    vector<int> result = mergeKArrays(arrays);

    for (int x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}