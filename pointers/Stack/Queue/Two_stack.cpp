#include <iostream>
#include <stack>
using namespace std;
class Queue {
    stack<int> s1, s2;
    public:
    void enqueue (int x){
        s1.push(x);
    }
    void dequeue(){
        if(s1.empty() && s2.empty()){
            cout<< "Queue is empty \n";
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        cout << "Removed: " << s2.top() << endl;
        s2.pop();
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}