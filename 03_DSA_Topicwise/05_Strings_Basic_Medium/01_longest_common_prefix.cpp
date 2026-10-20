#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> words(n);

    for (int i = 0; i < n; i++)
        cin >> words[i];

    if (n == 0) {
        cout << "Longest common prefix: " << endl;
        return 0;
    }

    string prefix = words[0];

    for (int i = 1; i < n; i++) {
        while (words[i].find(prefix) != 0) {
            prefix.pop_back();

            if (prefix.empty())
                break;
        }

        if (prefix.empty())
            break;
    }

    cout << "Longest common prefix: " << prefix << endl;
    return 0;
}