#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    for (int i = 0; i < n; i++) {
        cin >> heights[i];

        if (heights[i] < 0) {
            cout << "Heights cannot be negative." << endl;
            return 0;
        }
    }

    stack<int> st;
    long long maxArea = 0;

    for (int i = 0; i <= n; i++) {
        int currentHeight = (i == n ? 0 : heights[i]);

        while (!st.empty() &&
            heights[st.top()] > currentHeight) {
            int height = heights[st.top()];
            st.pop();

            int width = st.empty() ? i : i - st.top() - 1;

            maxArea = max(maxArea, 1LL * height * width);
        }

        st.push(i);
    }

    cout << "Largest rectangle area: " << maxArea << endl;

    return 0;
}