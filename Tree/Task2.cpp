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
//preorder traversal
void preorder(node* root) {
    if(root == NULL) return;

    cout << root->data << " ";
    preorder(root-> left);
    preorder(root->right);
}
//inorder traversal
void inorder(node* root) {
    if(root == NULL) return;

    inorder(root-> left);
    cout << root->data << " ";
    inorder(root->right);
}
//postorder traversal
void postorder(node* root) {
    if(root == NULL) return;
    postorder(root-> left);
    postorder(root->right);
    
        cout << root->data << " ";
}
int main(){
    // creating nodes 
    node* A = createNode('A');
    node* B = createNode('B');
    node* C = createNode('C');
    node* D = createNode('D');
    node* E = createNode('E');
    node* F = createNode('F');
    //building tree manually
    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;
    //printing traversals
    cout << "Preorder: ";
    preorder(A);
    cout << "Inorder: ";
    inorder(A);

    cout << "Postorder: ";
    postorder(A);
    return 0;

}