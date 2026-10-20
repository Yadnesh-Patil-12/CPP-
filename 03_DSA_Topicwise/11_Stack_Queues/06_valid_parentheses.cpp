#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty()) {
                cout << "Invalid parentheses" << endl;
                return 0;
            }

            char top = st.top();
            st.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                cout << "Invalid parentheses" << endl;
                return 0;
            }
        } else {
            cout << "Invalid character" << endl;
            return 0;
        }
    }

    cout << (st.empty()
        ? "Valid parentheses"
        : "Invalid parentheses") << endl;

    return 0;
}