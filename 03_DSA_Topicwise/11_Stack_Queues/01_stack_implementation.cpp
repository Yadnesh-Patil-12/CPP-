#include <iostream>
#include <vector>
using namespace std;

class Stack {
    vector<int> data;

public:
    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        if (data.empty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Popped: " << data.back() << endl;
        data.pop_back();
    }

    void top() {
        if (data.empty())
            cout << "Stack is empty" << endl;
        else
            cout << "Top: " << data.back() << endl;
    }

    void display() {
        for (int i = (int)data.size() - 1; i >= 0; i--)
            cout << data[i] << " ";

        cout << endl;
    }
};

int main() {
    Stack st;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        st.push(x);
    }

    st.display();
    st.top();
    st.pop();
    st.display();

    return 0;
}