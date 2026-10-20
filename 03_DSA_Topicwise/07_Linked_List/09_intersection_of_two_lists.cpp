#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* findIntersection(Node* a, Node* b) {
    Node* p = a;
    Node* q = b;

    while (p != q) {
        p = p ? p->next : b;
        q = q ? q->next : a;
    }

    return p;
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

    // The two lists are independently created here,
    // so they have no shared nodes by default.
    Node* intersection = findIntersection(a, b);

    if (intersection)
        cout << "Intersection value: " << intersection->data << endl;
    else
        cout << "No intersection" << endl;

    while (a) {
        Node* temp = a;
        a = a->next;
        delete temp;
    }

    while (b) {
        Node* temp = b;
        b = b->next;
        delete temp;
    }

    return 0;
}