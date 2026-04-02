#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue
    void dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        // Move elements if s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << s2.top() << " deleted\n";
        s2.pop();
    }

    // Display front element
    void front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty\n";
            return;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        cout << "Front: " << s2.top() << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front();
    q.dequeue();
    q.front();

    return 0;
}