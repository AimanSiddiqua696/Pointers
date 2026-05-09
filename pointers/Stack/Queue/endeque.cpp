#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node* rear;

public:
    Queue() {
        rear = NULL;
    }

    // Enqueue
    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;

        if (rear == NULL) {
            rear = newNode;
            rear->next = rear;
        } else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " inserted\n";
    }

    // Dequeue
    void dequeue() {
        if (rear == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* temp;

        // Only one node
        if (rear->next == rear) {
            temp = rear;
            rear = NULL;
        } else {
            temp = rear->next;
            rear->next = temp->next;
        }

        cout << temp->data << " deleted\n";
        delete temp;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.dequeue();
    return 0;
}