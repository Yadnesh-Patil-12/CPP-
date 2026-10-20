#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* merge(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;

    while (a && b) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    tail->next = a ? a : b;
    return dummy.next;
}

Node* sortList(Node* head) {
    if (!head || !head->next)
        return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = slow->next;
    slow->next = nullptr;

    Node* left = sortList(head);
    Node* right = sortList(second);

    return merge(left, right);
}

int main() {
    int n, x;
    cin >> n;

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

    head = sortList(head);

    while (head) {
        cout << head->data << " ";
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << endl;
    return 0;
}