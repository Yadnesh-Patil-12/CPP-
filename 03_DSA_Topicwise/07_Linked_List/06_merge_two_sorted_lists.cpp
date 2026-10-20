#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* mergeLists(Node* a, Node* b) {
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

int main() {
    int n, m, x;
    cin >> n;

    Node* a = nullptr;
    Node* tailA = nullptr;

    for (int i = 0; i < n; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!a) a = tailA = node;
        else {
            tailA->next = node;
            tailA = node;
        }
    }

    cin >> m;

    Node* b = nullptr;
    Node* tailB = nullptr;

    for (int i = 0; i < m; i++) {
        cin >> x;
        Node* node = new Node(x);

        if (!b) b = tailB = node;
        else {
            tailB->next = node;
            tailB = node;
        }
    }

    Node* result = mergeLists(a, b);

    while (result) {
        cout << result->data << " ";
        Node* temp = result;
        result = result->next;
        delete temp;
    }

    cout << endl;
    return 0;
}