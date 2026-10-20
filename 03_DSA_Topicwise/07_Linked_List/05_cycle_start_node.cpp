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

    int position;
    cout << "Enter cycle position (0 for no cycle): ";
    cin >> position;

    Node* cycleNode = nullptr;
    Node* temp = head;

    for (int i = 1; temp; i++) {
        if (i == position)
            cycleNode = temp;

        if (!temp->next)
            tail = temp;

        temp = temp->next;
    }

    if (position > 0 && cycleNode)
        tail->next = cycleNode;

    Node* slow = head;
    Node* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (!fast || !fast->next) {
        cout << "No cycle found" << endl;
    } else {
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        cout << "Cycle starts at node: " << slow->data << endl;
    }

    // Break cycle before deleting nodes.
    if (fast && fast->next) {
        slow = head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        Node* cycleStart = slow;
        Node* last = cycleStart;

        while (last->next != cycleStart)
            last = last->next;

        last->next = nullptr;
    }

    while (head) {
        Node* nextNode = head->next;
        delete head;
        head = nextNode;
    }

    return 0;
}