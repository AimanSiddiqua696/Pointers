#include <iostream>
#include <vector>
using namespace std;
class Node {
    public: 
    int data;
    Node* left;
    Node* right;

    // constructor
    Node(int value){
        data = value;
        left = right = NULL;
    }
    
};
static int idx = -1;
Node* buildTree(vector<int> preorder){
    idx++;
    if(preorder[idx] == -1){
        return NULL;
    }
    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);// left
    root->right = buildTree(preorder);// right
    return root;



}
void printPreorder(Node* root){
    if(root == NULL){
        cout <<"NULL" << endl;
        return;
    }
    cout << root->data << endl;
    printPreorder (root -> left);
    printPreorder (root -> right);
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    cout << root->data <<endl;
    // cout << root->left->data <<endl;
    // cout << root->right->data <<endl;
    printPreorder(root->left);
    printPreorder(root->right);
    return 0;

}