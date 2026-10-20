#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int x) {
    if (!root) return new Node(x);

    if (x < root->data)
        root->left = insert(root->left, x);
    else if (x > root->data)
        root->right = insert(root->right, x);

    return root;
}

int main() {
    int n;
    cin >> n;

    Node* root = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insert(root, x);
    }

    int k;
    cin >> k;

    stack<Node*> st;
    Node* curr = root;
    int count = 0;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        count++;

        if (count == k) {
            cout << "Kth smallest: " << curr->data << endl;
            return 0;
        }

        curr = curr->right;
    }

    cout << "Invalid k" << endl;
    return 0;
}