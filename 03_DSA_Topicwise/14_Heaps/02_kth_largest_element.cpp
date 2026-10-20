#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(vector<int>& a, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : a) {
        pq.push(x);

        if ((int)pq.size() > k)
            pq.pop();
    }

    if (k <= 0 || k > (int)a.size())
        return -1;

    return pq.top();
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int& x : a) cin >> x;

    int k;
    cin >> k;

    if (k < 1 || k > n) {
        cout << "Invalid k\n";
        return 0;
    }

    cout << "Kth largest: " << kthLargest(a, k) << endl;

    return 0;
}