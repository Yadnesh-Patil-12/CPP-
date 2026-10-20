#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++)
        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(),
         [](const Job& a, const Job& b) {
             return a.profit > b.profit;
         });

    int maxDeadline = 0;

    for (const auto& job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<char> slots(maxDeadline + 1, '\0');

    int jobsDone = 0;
    long long totalProfit = 0;

    for (const auto& job : jobs) {
        if (job.deadline <= 0 || job.profit <= 0)
            continue;

        for (int t = min(job.deadline, maxDeadline); t >= 1; t--) {
            if (slots[t] == '\0') {
                slots[t] = job.id;
                jobsDone++;
                totalProfit += job.profit;
                break;
            }
        }
    }

    cout << "Scheduled jobs: ";

    for (int t = 1; t <= maxDeadline; t++) {
        if (slots[t] != '\0')
            cout << slots[t] << " ";
    }

    cout << "\nJobs completed: " << jobsDone << endl;
    cout << "Total profit: " << totalProfit << endl;

    return 0;
}