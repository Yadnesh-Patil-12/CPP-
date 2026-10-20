#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& candidates, int index,
                      int target, vector<int>& current) {
    if (target == 0) {
        for (int x : current)
            cout << x << " ";

        cout << endl;
        return;
    }

    if (index == (int)candidates.size() || target < 0)
        return;

    // Include the current candidate
    current.push_back(candidates[index]);

    findCombinations(candidates, index,
                     target - candidates[index], current);

    current.pop_back();

    // Exclude the current candidate
    findCombinations(candidates, index + 1,
                     target, current);
}

int main() {
    int n, target;
    cin >> n;

    vector<int> candidates(n);

    for (int i = 0; i < n; i++) {
        cin >> candidates[i];

        if (candidates[i] <= 0) {
            cout << "Candidates must be positive." << endl;
            return 0;
        }
    }

    cin >> target;

    vector<int> current;

    findCombinations(candidates, 0, target, current);

    return 0;
}