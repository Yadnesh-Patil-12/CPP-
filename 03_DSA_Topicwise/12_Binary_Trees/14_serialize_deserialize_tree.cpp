#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

void serialize(Node* root, stringstream& ss) {
    if (!root) {
        ss << "# ";
        return;
    }

    ss << root->data << " ";
    serialize(root->left, ss);
    serialize(root->right, ss);
}

Node* deserialize(vector<string>& tokens, int& i) {
    if (i >= (int)tokens.size() || tokens[i] == "#") {
        i++;
        return nullptr;
    }

    Node* root = new Node(stoi(tokens[i++]));
    root->left = deserialize(tokens, i);
    root->right = deserialize(tokens, i);

    return root;
}

void preorder(Node* root) {
    if (!root) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    cin >> n;

    vector<int> values(n);
    for (int& x : values) cin >> x;

    int pos = 0;

    auto build = [&](auto&& self) -> Node* {
        if (pos >= n || values[pos] == -1) {
            pos++;
            return nullptr;
        }

        Node* root = new Node(values[pos++]);
        root->left = self(self);
        root->right = self(self);

        return root;
    };

    Node* root = build(build);

    stringstream ss;
    serialize(root, ss);

    string serialized = ss.str();
    cout << "Serialized: " << serialized << endl;

    vector<string> tokens;
    string token;
    stringstream input(serialized);

    while (input >> token)
        tokens.push_back(token);

    int i = 0;
    Node* restored = deserialize(tokens, i);

    cout << "Deserialized preorder: ";
    preorder(restored);

    cout << endl;
    return 0;
}