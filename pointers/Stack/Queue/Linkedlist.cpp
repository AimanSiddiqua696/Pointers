#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Queue{
    Node* front;
    Node* rear;
    public:
    Queue(){
        front = rear = NULL;

    }
    void enqueue(int value){
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        if(rear == NULL){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << "inserted\n";

    }
    void dequeue(){
        if(front == NULL){
            cout << "Queue is empty\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " deleted\n";
        front = front->next;
        if( front == NULL){
            rear = NULL;
        }
        delete temp;
    }
    void Display(){

            Node* temp = front;
            while (temp !=NULL){
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;

        }
    };


int main(){
Queue q;
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.Display();
q.dequeue();
q.dequeue();
return 0;
}