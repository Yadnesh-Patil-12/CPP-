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

    int target;
    cin >> target;

    unordered_map<int, int> seen;

    for (int i = 0; i < n; i++) {
        long long complement = (long long)target - a[i];

        if (complement >= -2147483648LL &&
            complement <= 2147483647LL) {
            auto it = seen.find((int)complement);

            if (it != seen.end()) {
                cout << "Indices: " << it->second
                     << " " << i << endl;
                return 0;
            }
        }

        seen[a[i]] = i;
    }

    cout << "No pair found" << endl;
    return 0;
}