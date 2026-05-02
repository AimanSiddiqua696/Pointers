#include <iostream>
using namespace std;
//node structure
struct node {
    char data;
    node* left;
    node* right;

};
//create new node 
node* createNode(char value){
    node*newnode = new node;
    newnode->data = value; // allocates memory in heap
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
//function to count nodes
int countnodes(node* root){
    if(root == NULL)
    return 0;
    return 1 + countnodes(root->left) + countnodes(root->right);
}
int main(){
    // creating tree 
    node* A = createNode('A');
    node* B = createNode('B');
    node* C = createNode('C');
    node* D = createNode('D');
    node* E = createNode('E');
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    //count nodes
    cout << "Total nodes: " << countnodes(A);
    return 0;
}