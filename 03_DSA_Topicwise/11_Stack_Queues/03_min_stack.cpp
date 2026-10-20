#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;

public:
    void push(int x) {
        int minimum = st.empty()
            ? x
            : min(x, st.top().second);

        st.push({x, minimum});
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        st.pop();
    }

    void top() {
        if (st.empty())
            cout << "Stack is empty" << endl;
        else
            cout << "Top: " << st.top().first << endl;
    }

    void getMin() {
        if (st.empty())
            cout << "Stack is empty" << endl;
        else
            cout << "Minimum: " << st.top().second << endl;
    }
};

int main() {
    MinStack st;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        st.push(x);
    }

    st.top();
    st.getMin();
    st.pop();
    st.getMin();

    return 0;
}