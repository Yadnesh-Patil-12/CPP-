#include <iostream>
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

bool floorCeil(Node* root, int key, int& floorVal, int& ceilVal) {
    bool hasFloor = false, hasCeil = false;

    while (root) {
        if (root->data == key) {
            floorVal = ceilVal = key;
            return true;
        }

        if (root->data < key) {
            floorVal = root->data;
            hasFloor = true;
            root = root->right;
        } else {
            ceilVal = root->data;
            hasCeil = true;
            root = root->left;
        }
    }

    cout << "Floor: ";
    if (hasFloor) cout << floorVal;
    else cout << "Not found";

    cout << "\nCeil: ";
    if (hasCeil) cout << ceilVal;
    else cout << "Not found";

    cout << endl;
    return false;
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

    int key, f = 0, c = 0;
    cin >> key;

    if (floorCeil(root, key, f, c)) {
        cout << "Floor: " << f << "\nCeil: " << c << endl;
    }

    return 0;
}