#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MinHeap {
    vector<int> heap;

public:
    void insert(int x) {
        heap.push_back(x);
        int i = heap.size() - 1;

        while (i > 0) {
            int p = (i - 1) / 2;

            if (heap[p] <= heap[i]) break;

            swap(heap[p], heap[i]);
            i = p;
        }
    }

    void deleteMin() {
        if (heap.empty()) {
            cout << "Heap is empty\n";
            return;
        }

        heap[0] = heap.back();
        heap.pop_back();

        int i = 0, n = heap.size();

        while (true) {
            int smallest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    int getMin() {
        if (heap.empty()) return -1;
        return heap[0];
    }

    void display() {
        for (int x : heap) cout << x << " ";
        cout << endl;
    }
};

int main() {
    MinHeap h;
    int n, x;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        h.insert(x);
    }

    cout << "Min Heap: ";
    h.display();

    cout << "Minimum: " << h.getMin() << endl;

    h.deleteMin();

    cout << "After deleting minimum: ";
    h.display();

    return 0;
}