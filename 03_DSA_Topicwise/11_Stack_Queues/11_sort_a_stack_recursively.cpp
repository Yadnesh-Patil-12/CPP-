#include <iostream>
#include <stack>
using namespace std;

void insertSorted(stack<int>& st, int value) {
    if (st.empty() || st.top() <= value) {
        st.push(value);
        return;
    }

    int top = st.top();
    st.pop();

    insertSorted(st, value);

    st.push(top);
}

void sortStack(stack<int>& st) {
    if (st.empty())
        return;

    int value = st.top();
    st.pop();

    sortStack(st);
    insertSorted(st, value);
}

int main() {
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        st.push(x);
    }

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
    return 0;
}