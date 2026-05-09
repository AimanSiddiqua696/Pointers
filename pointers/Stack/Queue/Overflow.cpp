#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;

public:
    // Constructor to initialize queue
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return (rear == size - 1);
    }

    // Enqueue operation
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n"; // handle overflow
            return;
        }
        if (front == -1) front = 0; // first element
        rear++;
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n"; // handle underflow
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
        if (front > rear) front = rear = -1; // reset queue when empty
    }

    // Display all queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue of size 5

    // Enqueue some elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Try to enqueue more elements (overflow)
    q.enqueue(60);

    // Display queue
    q.display();

    // Dequeue some elements
    q.dequeue();
    q.dequeue();

    // Display queue again
    q.display();

    // Dequeue all elements to trigger underflow
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // underflow occurs

    return 0;
}