#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
    stack<int> input, output;

    void transfer() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    void enqueue(int x) {
        input.push(x);
    }

    void dequeue() {
        transfer();

        if (output.empty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Removed: " << output.top() << endl;
        output.pop();
    }

    void front() {
        transfer();

        if (output.empty())
            cout << "Queue is empty" << endl;
        else
            cout << "Front: " << output.top() << endl;
    }
};

int main() {
    MyQueue q;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    q.front();
    q.dequeue();
    q.front();

    return 0;
}