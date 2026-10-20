#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
    vector<int> arr;
    int frontIndex, rearIndex, count, capacity;

public:
    CircularQueue(int size)
        : arr(size), frontIndex(0), rearIndex(-1),
          count(0), capacity(size) {}

    bool enqueue(int value) {
        if (count == capacity) {
            cout << "Queue is full" << endl;
            return false;
        }

        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
        count++;

        return true;
    }

    bool dequeue() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return false;
        }

        cout << "Removed: " << arr[frontIndex] << endl;
        frontIndex = (frontIndex + 1) % capacity;
        count--;

        return true;
    }

    void display() {
        for (int i = 0; i < count; i++)
            cout << arr[(frontIndex + i) % capacity] << " ";

        cout << endl;
    }
};

int main() {
    int capacity;
    cin >> capacity;

    if (capacity <= 0) {
        cout << "Capacity must be positive" << endl;
        return 0;
    }

    CircularQueue q(capacity);

    int n, x;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        q.enqueue(x);
    }

    q.display();
    q.dequeue();
    q.display();

    return 0;
}