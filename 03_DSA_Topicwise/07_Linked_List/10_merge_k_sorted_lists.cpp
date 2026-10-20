#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

int main() {
    int k;
    cin >> k;

    vector<Node*> lists(k, nullptr);
    vector<Node*> tails(k, nullptr);

    for (int i = 0; i < k; i++) {
        int n;
        cin >> n;

        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;

            Node* node = new Node(x);

            if (!lists[i])
                lists[i] = tails[i] = node;
            else {
                tails[i]->next = node;
                tails[i] = node;
            }
        }
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (Node* head : lists)
        if (head) pq.push(head);

    while (!pq.empty()) {
        Node* current = pq.top();
        pq.pop();

        cout << current->data << " ";

        if (current->next)
            pq.push(current->next);

        delete current;
    }

    cout << endl;
    return 0;
}