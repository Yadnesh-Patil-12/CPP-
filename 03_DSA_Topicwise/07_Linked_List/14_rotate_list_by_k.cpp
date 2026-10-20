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

        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    long long k;
    cin >> k;

    if (!head || !head->next) {
        if (head) cout << head->data;
        cout << endl;
        delete head;
        return 0;
    }

    int length = 1;
    for (Node* p = head; p->next; p = p->next)
        length++;

    k = ((k % length) + length) % length;

    if (k != 0) {
        tail->next = head;

        int steps = length - static_cast<int>(k);
        Node* newTail = head;

        for (int i = 1; i < steps; i++)
            newTail = newTail->next;

        head = newTail->next;
        newTail->next = nullptr;
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