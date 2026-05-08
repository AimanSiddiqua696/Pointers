#include <iostream>
using namespace std;
//node structure
struct node {
    char data;
    node* left;
    node* right;

};
//create  node 
node* createNode(char value){
    node*newnode = new node;
    newnode->data = value; // allocates memory in heap
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
//function to count leaf nodes
int countLeafNodes (node* root){
    if(root == NULL)
    return 0;
    //check if leaf node 
    if(root->left == NULL && root->right == NULL)
    return 1;
    // otherwise check left and right 
    return countLeafNodes(root->left) + countLeafNodes(root->right); 
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
    //count leaf nodes
    cout << "Leaf nodes: " << countLeafNodes(A);
    return 0;
}