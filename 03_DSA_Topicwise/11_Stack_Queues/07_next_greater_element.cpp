#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> result(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= a[i])
            st.pop();

        if (!st.empty())
            result[i] = st.top();

        st.push(a[i]);
    }

    for (int x : result)
        cout << x << " ";

    cout << endl;
    return 0;
}