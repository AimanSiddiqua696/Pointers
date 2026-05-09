// Write a program to check whether a given tree is a valid BST or not. 
#include <iostream>
using namespace std;
struct Node{
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
    if(root ==NULL){
        return new Node (value);
    }
    if(value < root-> data){
        root-> left = insert(root->left, value);
    } else if(value > root->data){
        root-> right = insert(root->right, value);

    }
    return root;
}
bool isBst(Node* root , int min, int max){
    if(root ==NULL){
        return true;
    }
    if(root->data < min || root->data > max){
        return false;
    }
    return isBst(root->left ,min,root->data) && isBst(root-> right, root->data, max);
}

int sum = 0;
void preOrder(Node* root){
    if(root==NULL){
        return;
    }
   
    

  
    preOrder(root-> left);
    preOrder(root-> right);
};
int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 100);
    insert(root, 50);
    insert(root, 150);
    insert(root, 30);
    insert(root, 70);
    insert(root, 120);
    insert(root, 170);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    preOrder(root);
   
if(isBst(root, -100000, 100000)){
    cout<<"Tree is valid BST ";
} else {
    cout<<" Tree is not valid BST ";
}
return 0;
}
   