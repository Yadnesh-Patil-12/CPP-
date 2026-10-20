#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* buildTree(const vector<int>& a, int& i) {
    if (i >= (int)a.size() || a[i] == -1) {
        i++;
        return nullptr;
    }

    Node* root = new Node(a[i++]);
    root->left = buildTree(a, i);
    root->right = buildTree(a, i);
    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int& x : a) cin >> x;

    int i = 0;
    Node* root = buildTree(a, i);

    stack<Node*> st;
    Node* curr = root;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << " ";
        curr = curr->right;
    }

    cout << endl;
    return 0;
}