#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frequency[x]++;
    }

    for (auto p : frequency)
        cout << p.first << " occurs "
             << p.second << " times" << endl;

    return 0;
}