#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    unordered_set<int> values(a.begin(), a.end());
    unordered_set<int> result;

    for (int x : b) {
        if (values.count(x))
            result.insert(x);
    }

    vector<int> answer(result.begin(), result.end());
    sort(answer.begin(), answer.end());

    cout << "Intersection: ";
    for (int x : answer)
        cout << x << " ";

    cout << endl;
    return 0;
}