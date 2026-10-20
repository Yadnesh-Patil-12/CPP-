#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);
    vector<int> answer(n, 0);
    stack<int> st;

    for (int i = 0; i < n; i++)
        cin >> temperatures[i];

    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int previous = st.top();
            st.pop();

            answer[previous] = i - previous;
        }

        st.push(i);
    }

    for (int x : answer)
        cout << x << " ";

    cout << endl;
    return 0;
}