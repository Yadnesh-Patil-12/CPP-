#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    void push(int x) {
        q.push(x);

        int size = q.size();

        for (int i = 0; i < size - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top() {
        if (q.empty())
            cout << "Stack is empty" << endl;
        else
            cout << "Top: " << q.front() << endl;
    }
};

int main() {
    MyStack st;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        st.push(x);
    }

    st.top();
    st.pop();
    st.top();

    return 0;
}