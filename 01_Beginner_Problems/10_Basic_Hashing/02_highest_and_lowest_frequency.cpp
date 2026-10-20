#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 0) return 0;

    unordered_map<int, int> frequency;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        frequency[x]++;
    }

    int highestElement = 0, lowestElement = 0;
    int highest = 0, lowest = n + 1;

    for (auto p : frequency) {
        if (p.second > highest ||
            (p.second == highest && p.first < highestElement)) {
            highest = p.second;
            highestElement = p.first;
        }

        if (p.second < lowest ||
            (p.second == lowest && p.first < lowestElement)) {
            lowest = p.second;
            lowestElement = p.first;
        }
    }

    cout << "Highest frequency: " << highestElement
         << " occurs " << highest << " times" << endl;

    cout << "Lowest frequency: " << lowestElement
         << " occurs " << lowest << " times" << endl;

    return 0;
}