#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void sortKSorted(vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> result;

    for (int x : a) {
        pq.push(x);

        if ((int)pq.size() > k)
        {
            result.push_back(pq.top());
            pq.pop();
        }
    }

    while (!pq.empty()) {
        result.push_back(pq.top());
        pq.pop();
    }

    a = result;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int& x : a) cin >> x;

    sortKSorted(a, k);

    for (int x : a)
        cout << x << " ";

    cout << endl;
    return 0;
}