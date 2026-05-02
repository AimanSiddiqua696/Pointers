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
    newnode->data = value; 
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

int countnodes(node* root){
    if(root == NULL)
    return 0;

    return 1 + countnodes(root->left);
}
int countnode(node* root){
    if(root == NULL)
    return 0;

    return 1 + countnodes(root->right);
}
int main(){
   
    node* A = createNode('A');
    node* B = createNode('B');
    node* C = createNode('C');
    node* D = createNode('D');
    node* E = createNode('E');
    A->left = B;
    B->left = D;
    A->right = C;
    B->right = E;

    cout << "Total nodes left: " << countnodes(A) <<endl;
    cout << "Total nodes right: " << countnode(A);
    return 0;
}