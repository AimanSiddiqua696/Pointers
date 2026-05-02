#include <iostream>
using namespace std;
//node structure
struct node {
    char data;
    node* firstchild;
    node* nextsibling;

};

// function to create a new node 
node* createNode(char value){
    node*newnode = new node;
    newnode->data = value; // allocates memory in heap
    newnode->firstchild = NULL;
    newnode->nextsibling = NULL;
    return newnode;
}
//function to print tree(preorder traversal) 
void printTree(node* root){
    if(root == NULL)
    return;
    cout << root->data << " "; //print current node
    // visit child 
    printTree(root->firstchild);

    //visit sibling
    printTree(root->nextsibling);
}
int main(){
    // creating nodes 
    node* A = createNode('A');
    node* B = createNode('B');
    node* C = createNode('C');
    node* D = createNode('D');
    node* E = createNode('E');
    node* F = createNode('F');
    //Building tree 
    A->firstchild =B;
    B->nextsibling = C;
    C->nextsibling = D;
    B->firstchild =E;
    E->nextsibling = F;
    //printing tree
    cout <<"Tree nodes are: ";
    printTree(A);

    return 0;



}