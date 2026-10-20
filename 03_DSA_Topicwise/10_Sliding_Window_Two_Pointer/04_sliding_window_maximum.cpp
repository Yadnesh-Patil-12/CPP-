#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (n <= 0 || k <= 0 || k > n) {
        cout << "Invalid input" << endl;
        return 0;
    }

    vector<int> a(n);
    deque<int> dq;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        while (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        while (!dq.empty() && a[dq.back()] <= a[i])
            dq.pop_back();

        dq.push_back(i);

        if (i >= k - 1)
            cout << a[dq.front()] << " ";
    }

    cout << endl;
    return 0;
}