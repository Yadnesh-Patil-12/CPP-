#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int result = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        result ^= a[i];
    }

    cout << "Single number: " << result << endl;
    return 0;
}