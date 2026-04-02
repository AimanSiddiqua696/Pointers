#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max-heap by default → highest element first
    priority_queue<int> pq;

    // Enqueue elements
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Priority Queue Elements (Dequeue order): ";
    while (!pq.empty()) {
        cout << pq.top() << " "; // Highest priority element
        pq.pop();
    }

    return 0;
}