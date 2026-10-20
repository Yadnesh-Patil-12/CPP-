#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    vector<int> gas(n), cost(n);

    for (int i = 0; i < n; i++)
        cin >> gas[i];

    for (int i = 0; i < n; i++)
        cin >> cost[i];

    int start = 0;
    long long total = 0;
    long long current = 0;

    for (int i = 0; i < n; i++) {
        long long difference = (long long)gas[i] - cost[i];

        total += difference;
        current += difference;

        if (current < 0) {
            start = i + 1;
            current = 0;
        }
    }

    if (total < 0)
        cout << "Circuit cannot be completed" << endl;
    else
        cout << "Starting station: " << start << endl;

    return 0;
}