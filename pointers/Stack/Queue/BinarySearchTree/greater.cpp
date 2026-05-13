// Write a program to count nodes greater than a given value k. 
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

int cnt = 0;
int k;
void inorder(Node* root){
 if(root == NULL)
 return;
 
 inorder(root-> left);

 if(root->data > k){
   cnt ++;
    
 }

 inorder(root-> right);
 
 
 
};

int main(){
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 100);
    insert(root, 150);
    insert(root, 30);
    insert(root, 70);
    insert(root, 120);
    insert(root, 170);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout<<"Enter the value of k : ";
    cin >> k;
    cnt = 0;
    inorder(root);
    cout<< cnt;
    
return 0;
}