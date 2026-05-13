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

int countLeaf(Node* root){
    if( root ==NULL)
    return 0;
    if( root ->left == NULL &&  root ->right == NULL )
    return 1;
    return countLeaf(root->left) + countLeaf(root-> right);
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

    cout<< countLeaf(root);
return 0;
}