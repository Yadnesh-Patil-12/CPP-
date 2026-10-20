#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

Node* buildTree() {
    int x;
    cin >> x;

    if (x == -1) return nullptr;

    Node* root = new Node(x);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    Node* root = buildTree();

    if (!root) return 0;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level(size);

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();

            int index = leftToRight ? i : size - 1 - i;
            level[index] = curr->data;

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }

        for (int x : level)
            cout << x << " ";

        leftToRight = !leftToRight;
    }

    cout << endl;
    return 0;
}