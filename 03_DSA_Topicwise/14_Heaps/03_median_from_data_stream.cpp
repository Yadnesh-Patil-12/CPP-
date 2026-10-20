#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
    priority_queue<int> leftMax;
    priority_queue<int, vector<int>, greater<int>> rightMin;

public:
    void addNum(int x) {
        leftMax.push(x);

        rightMin.push(leftMax.top());
        leftMax.pop();

        if (leftMax.size() < rightMin.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }

    double findMedian() {
        if (leftMax.size() > rightMin.size())
            return leftMax.top();

        return ((double)leftMax.top() + rightMin.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        mf.addNum(x);

        cout << "Median: " << mf.findMedian() << endl;
    }

    return 0;
}