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

int leftcountTotal(Node* root){
    if(root == NULL){
        return 0;

    }
    int count =0;
    count += leftcountTotal(root->left);
    return count + 1;


    }
int rightcountTotal(Node* root){
    if(root == NULL){
        return 0;

    }
    int count =0;
    count += rightcountTotal(root -> right);
    return count + 1;


    }


int totalCount(Node* root){
    int total = leftcountTotal(root) + rightcountTotal(root);
    return total + 1;
    
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
    
    cout<<totalCount(root);



   return 0;
}