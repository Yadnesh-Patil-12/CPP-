#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long target;
    cin >> target;

    unordered_map<long long, long long> frequency;
    long long pairs = 0;

    for (int x : a) {
        long long needed = target - x;

        if (frequency.count(needed))
            pairs += frequency[needed];

        frequency[x]++;
    }

    cout << "Number of pairs: " << pairs << endl;
    return 0;
}