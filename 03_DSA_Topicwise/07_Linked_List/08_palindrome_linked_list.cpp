#include <iostream>
#include <vector>
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

    vector<int> values;

    for (Node* current = head; current; current = current->next)
        values.push_back(current->data);

    bool palindrome = true;

    for (int i = 0, j = (int)values.size() - 1; i < j; i++, j--) {
        if (values[i] != values[j]) {
            palindrome = false;
            break;
        }
    }

    cout << (palindrome ? "Palindrome" : "Not palindrome") << endl;

    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}