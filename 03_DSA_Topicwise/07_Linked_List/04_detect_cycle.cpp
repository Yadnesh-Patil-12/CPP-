#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    int n, x;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!head)
            head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    // This input builds an acyclic list.
    // Change a next pointer to test a cycle.

    Node* slow = head;
    Node* fast = head;
    bool hasCycle = false;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            hasCycle = true;
            break;
        }
    }

    cout << (hasCycle ? "Cycle detected" : "No cycle") << endl;

    // Do not delete nodes by normal traversal if a cycle exists.
    if (!hasCycle) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    return 0;
}