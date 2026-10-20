#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int leastInterval(vector<char>& tasks, int cooldown) {
    unordered_map<char, int> freq;

    for (char c : tasks)
        freq[c]++;

    priority_queue<int> pq;

    for (auto& p : freq)
        pq.push(p.second);

    int time = 0;

    while (!pq.empty()) {
        vector<int> remaining;
        int cycle = cooldown + 1;

        for (int i = 0; i < cycle; i++) {
            if (!pq.empty()) {
                int count = pq.top();
                pq.pop();

                count--;

                if (count > 0)
                    remaining.push_back(count);
            }

            time++;

            if (pq.empty() && remaining.empty())
                break;
        }

        for (int count : remaining)
            pq.push(count);
    }

    return time;
}

int main() {
    int n, cooldown;
    cin >> n >> cooldown;

    vector<char> tasks(n);

    for (char& c : tasks)
        cin >> c;

    cout << "Minimum intervals: "
         << leastInterval(tasks, cooldown) << endl;

    return 0;
}