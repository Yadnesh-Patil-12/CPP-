#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    string token;
    stack<long long> st;

    while (ss >> token) {
        if (token == "+" || token == "-" ||
            token == "*" || token == "/") {

            if (st.size() < 2) {
                cout << "Invalid expression" << endl;
                return 0;
            }

            long long b = st.top();
            st.pop();

            long long a = st.top();
            st.pop();

            if (token == "+")
                st.push(a + b);
            else if (token == "-")
                st.push(a - b);
            else if (token == "*")
                st.push(a * b);
            else {
                if (b == 0) {
                    cout << "Division by zero" << endl;
                    return 0;
                }

                st.push(a / b);
            }
        } else {
            try {
                size_t pos;
                long long value = stoll(token, &pos);

                if (pos != token.size())
                    throw invalid_argument("Invalid token");

                st.push(value);
            } catch (...) {
                cout << "Invalid token: " << token << endl;
                return 0;
            }
        }
    }

    if (st.size() != 1) {
        cout << "Invalid expression" << endl;
        return 0;
    }

    cout << "Result: " << st.top() << endl;

    return 0;
}