#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

void insertAtEnd(Node*& head, Node*& tail, int value) {
    Node* node = new Node(value);

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void deleteValue(Node*& head, Node*& tail, int value) {
    Node* current = head;

    while (current && current->data != value)
        current = current->next;

    if (!current) return;

    if (current->prev)
        current->prev->next = current->next;
    else
        head = current->next;

    if (current->next)
        current->next->prev = current->prev;
    else
        tail = current->prev;

    delete current;
}

void displayForward(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void displayBackward(Node* tail) {
    while (tail) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        insertAtEnd(head, tail, x);
    }

    cout << "Forward: ";
    displayForward(head);

    cout << "Backward: ";
    displayBackward(tail);

    cout << "Enter value to delete: ";
    cin >> x;

    deleteValue(head, tail, x);

    cout << "After deletion: ";
    displayForward(head);

    freeList(head);
    tail = nullptr;

    return 0;
}