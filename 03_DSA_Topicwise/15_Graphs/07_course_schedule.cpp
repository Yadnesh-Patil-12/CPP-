#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int courses, prerequisites;
    cin >> courses >> prerequisites;

    vector<vector<int>> adj(courses);
    vector<int> indegree(courses, 0);

    for (int i = 0; i < prerequisites; i++) {
        int course, prerequisite;
        cin >> course >> prerequisite;

        adj[prerequisite].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    for (int i = 0; i < courses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int completed = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        completed++;

        for (int v : adj[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    cout << (completed == courses
        ? "All courses can be completed"
        : "Course schedule is impossible") << endl;

    return 0;
}