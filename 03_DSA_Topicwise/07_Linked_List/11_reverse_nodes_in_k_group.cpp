#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* reverseKGroup(Node* head, int k) {
    if (!head || k <= 1) return head;

    Node* current = head;
    int count = 0;

    while (current && count < k) {
        current = current->next;
        count++;
    }

    if (count < k) return head;

    Node* prev = nullptr;
    current = head;

    for (int i = 0; i < k; i++) {
        Node* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    head->next = reverseKGroup(current, k);

    return prev;
}

int main() {
    int n, x, k;
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

    cin >> k;

    head = reverseKGroup(head, k);

    while (head) {
        cout << head->data << " ";
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    cout << endl;
    return 0;
}