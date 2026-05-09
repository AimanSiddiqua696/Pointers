#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value){
        data = value;
        left = right = NULL;
    }
};



//insert
Node* insert(Node* root, int value){
    if(root == NULL){
     return new Node(value);
    }
    if(value < root->data){
        root -> left = insert(root->left, value);

    } else if(value > root -> data){
        root ->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root , int key){
    if(root == NULL){
        return false;
    }
    if(root ->data == key){
        return true;
    }
    if(key < root->data)
    return search(root-> left, key);
    else 
    return search(root-> right, key);
}
int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "search 40: "<< (search(root, 40 ) ? "Found" : "Not Found");
    cout<<endl;
    cout << "search 35: "<< (search(root, 35 ) ? "Found" : "Not Found");
    cout<<endl;
    cout << "search 90: "<< (search(root, 90) ? "Found": "Not Found");
return 0;
}