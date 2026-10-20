#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item {
    double value, weight;
};

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);

    for (int i = 0; i < n; i++)
        cin >> items[i].value >> items[i].weight;

    double capacity;
    cin >> capacity;

    for (const auto& item : items) {
        if (item.weight <= 0 || item.value < 0) {
            cout << "Invalid item values." << endl;
            return 0;
        }
    }

    sort(items.begin(), items.end(),
         [](const Item& a, const Item& b) {
             return a.value / a.weight > b.value / b.weight;
         });

    double totalValue = 0;

    for (const auto& item : items) {
        if (capacity <= 0) break;

        double take = min(capacity, item.weight);

        totalValue += take * item.value / item.weight;
        capacity -= take;
    }

    cout << fixed << setprecision(2);
    cout << "Maximum value: " << totalValue << endl;

    return 0;
}