#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(const vector<int>& a, int index, int target) {
    if (target == 0)
        return true;

    if (index == (int)a.size())
        return false;

    // Exclude current element
    if (subsetSum(a, index + 1, target))
        return true;

    // Include current element
    return subsetSum(a, index + 1, target - a[index]);
}

int main() {
    int n, target;
    cin >> n;

    if (n < 0 || n > 30) {
        cout << "Enter n between 0 and 30." << endl;
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> target;

    if (subsetSum(a, 0, target))
        cout << "Subset sum exists" << endl;
    else
        cout << "Subset sum does not exist" << endl;

    return 0;
}