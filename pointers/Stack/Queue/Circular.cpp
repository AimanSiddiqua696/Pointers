#include <iostream>
using namespace std;

class CircularQueue {
    int front, rear, size;
    int* arr;

public:
    // Constructor
    CircularQueue(int s) {
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
        return ((rear + 1) % size == front);
    }

    // Enqueue operation
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0; // first element
        rear = (rear + 1) % size;
        arr[rear] = x;
        cout << x << " enqueued\n";
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        if (front == rear) {
            front = rear = -1; // reset queue
        } else {
            front = (front + 1) % size;
        }
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q(5); // size 5

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Try to enqueue more (Overflow)
    q.enqueue(60);

    // Display queue
    q.display();

    // Dequeue 2 elements
    q.dequeue();
    q.dequeue();

    // Display queue again
    q.display();

    // Enqueue 2 more elements (uses freed space)
    q.enqueue(60);
    q.enqueue(70);

    // Display final queue
    q.display();

    return 0;
}