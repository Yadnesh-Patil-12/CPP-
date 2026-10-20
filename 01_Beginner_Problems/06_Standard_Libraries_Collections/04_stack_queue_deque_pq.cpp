#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack top: " << st.top() << endl;
    st.pop();

    cout << "Stack after pop: " << st.top() << endl;

    queue<int> q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "\nQueue front: " << q.front() << endl;
    q.pop();

    cout << "Queue after pop: " << q.front() << endl;

    priority_queue<int> pq;

    pq.push(10);
    pq.push(50);
    pq.push(30);

    cout << "\nPriority Queue top: " << pq.top() << endl;

    deque<int> dq;

    dq.push_back(20);
    dq.push_front(10);
    dq.push_back(30);

    cout << "Deque: ";
    for (int x : dq) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}