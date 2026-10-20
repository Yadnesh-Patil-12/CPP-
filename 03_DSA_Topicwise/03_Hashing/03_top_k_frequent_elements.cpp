#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        frequency[a[i]]++;
    }

    cin >> k;

    vector<pair<int, int>> elements;

    for (auto p : frequency)
        elements.push_back({p.first, p.second});

    sort(elements.begin(), elements.end(),
         [](const pair<int, int>& a,
            const pair<int, int>& b) {
             if (a.second != b.second)
                 return a.second > b.second;
             return a.first < b.first;
         });

    if (k < 0) k = 0;
    k = min(k, (int)elements.size());

    for (int i = 0; i < k; i++)
        cout << elements[i].first << " ";

    cout << endl;
    return 0;
}