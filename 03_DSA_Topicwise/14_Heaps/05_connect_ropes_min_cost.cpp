#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long minCost(vector<int>& ropes) {
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : ropes)
        pq.push(x);

    long long cost = 0;

    while (pq.size() > 1) {
        long long a = pq.top();
        pq.pop();

        long long b = pq.top();
        pq.pop();

        long long sum = a + b;

        cost += sum;
        pq.push((int)sum);
    }

    return cost;
}

int main() {
    int n;
    cin >> n;

    vector<int> ropes(n);

    for (int& x : ropes) cin >> x;

    cout << "Minimum cost: " << minCost(ropes) << endl;

    return 0;
}