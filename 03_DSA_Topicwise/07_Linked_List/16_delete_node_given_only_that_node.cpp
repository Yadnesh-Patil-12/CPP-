#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

bool deleteGivenNode(Node* node) {
    if (!node || !node->next)
        return false;

    Node* nextNode = node->next;

    node->data = nextNode->data;
    node->next = nextNode->next;

    delete nextNode;
    return true;
}

int main() {
    int n, x;
    cin >> n;

    if (n < 2) {
        cout << "At least two nodes are required." << endl;
        return 0;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    int position;
    cin >> position;

    if (position < 1 || position >= n) {
        cout << "Choose a position from 1 to " << n - 1 << endl;
    } else {
        Node* target = head;

        for (int i = 1; i < position; i++)
            target = target->next;

        deleteGivenNode(target);
    }

    while (head) {
        cout << head->data << " ";
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << endl;
    return 0;
}