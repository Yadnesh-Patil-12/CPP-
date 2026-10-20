#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& a, int index) {
    if (index == (int)a.size()) {
        for (int x : a)
            cout << x << " ";

        cout << endl;
        return;
    }

    for (int i = index; i < (int)a.size(); i++) {
        swap(a[index], a[i]);

        generatePermutations(a, index + 1);

        swap(a[index], a[i]);
    }
}

int main() {
    int n;
    cin >> n;

    if (n < 0 || n > 10) {
        cout << "Enter n between 0 and 10." << endl;
        return 0;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    generatePermutations(a, 0);

    return 0;
}