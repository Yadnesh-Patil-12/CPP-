#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    vector<int> freq(256, 0);
    queue<unsigned char> q;

    for (unsigned char c : s) {
        freq[c]++;
        q.push(c);

        while (!q.empty() && freq[q.front()] > 1)
            q.pop();

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    cout << endl;
    return 0;
}