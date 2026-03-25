#include <iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;

public:
    
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

   
    bool isEmpty() {
        return (front == -1);
    }

   
    bool isFull() {
        return (rear == size - 1);
    }

   
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow!\n";
            return;
        }
        if (front == -1) front = 0; 
        rear++;
        arr[rear] = x;
        cout << x << " enqueued\n";
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front++;
        if (front > rear) front = rear = -1; 
    }

    
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q(5); 

    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();
    q.dequeue();

    q.display();

    return 0;
}