#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node(value);

    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
}

void deleteValue(Node*& head, int value) {
    if (!head) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    while (temp->next && temp->next->data != value)
        temp = temp->next;

    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }
}

void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
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
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Linked list: ";
    display(head);

    cout << "Enter value to insert: ";
    cin >> value;
    insertAtEnd(head, value);
    display(head);

    cout << "Enter value to delete: ";
    cin >> value;
    deleteValue(head, value);
    display(head);

    freeList(head);
    return 0;
}