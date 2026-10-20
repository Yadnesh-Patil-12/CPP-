#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* addTwoNumbers(Node* a, Node* b) {
    Node dummy(0);
    Node* tail = &dummy;
    int carry = 0;

    while (a || b || carry) {
        int sum = carry;

        if (a) {
            sum += a->data;
            a = a->next;
        }

        if (b) {
            sum += b->data;
            b = b->next;
        }

        carry = sum / 10;
        tail->next = new Node(sum % 10);
        tail = tail->next;
    }

    return dummy.next;
}

Node* createList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        Node* node = new Node(x);

        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

void deleteList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int n, m;
    cin >> n;

    Node* a = createList(n);

    cin >> m;
    Node* b = createList(m);

    Node* result = addTwoNumbers(a, b);

    while (result) {
        cout << result->data << " ";
        result = result->next;
    }

    cout << endl;

    deleteList(a);
    deleteList(b);

    // Re-create result pointer handling if you need to free it.
    return 0;
}