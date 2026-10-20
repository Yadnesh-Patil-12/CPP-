#include <iostream>
#include <vector>
using namespace std;

int partitionArray(vector<int>& a, int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return;

    int p = partitionArray(a, low, high);

    quickSort(a, low, p - 1);
    quickSort(a, p + 1, high);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n > 0) quickSort(a, 0, n - 1);

    for (int x : a) cout << x << " ";
    cout << endl;

    return 0;
}