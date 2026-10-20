#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arrival(n), departure(n);

    for (int i = 0; i < n; i++)
        cin >> arrival[i];

    for (int i = 0; i < n; i++)
        cin >> departure[i];

    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());

    int platforms = 0;
    int maximumPlatforms = 0;
    int i = 0, j = 0;

    while (i < n && j < n) {
        if (arrival[i] <= departure[j]) {
            platforms++;
            maximumPlatforms = max(maximumPlatforms, platforms);
            i++;
        } else {
            platforms--;
            j++;
        }
    }

    cout << "Minimum platforms required: "
         << maximumPlatforms << endl;

    return 0;
}