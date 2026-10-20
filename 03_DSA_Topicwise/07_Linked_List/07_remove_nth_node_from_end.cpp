#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

int main() {
    int n, x, k;
    cin >> n;

    Node dummy(0);
    Node* tail = &dummy;

    for (int i = 0; i < n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    cin >> k;

    if (k <= 0 || k > n) {
        cout << "Invalid position" << endl;
    } else {
        Node* fast = &dummy;
        Node* slow = &dummy;

        for (int i = 0; i < k; i++)
            fast = fast->next;

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        Node* deleted = slow->next;
        slow->next = deleted->next;
        delete deleted;
    }

    Node* current = dummy.next;

    while (current) {
        cout << current->data << " ";
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    cout << endl;
    return 0;
}