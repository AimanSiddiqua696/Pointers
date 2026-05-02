#include <iostream>
#include <vector>
#include <queue>
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
//preorder traversal
void printPreorder(Node* root){
    if(root == NULL){
        // cout <<"NULL" << endl;
        return;
    }
    cout << root->data << endl;
    printPreorder (root -> left);
    printPreorder (root -> right);
}
//Inorder traversal
void inOrder(Node* root){
    if (root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
//PostOrder traversal
void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data<<" ";
}
//level order
void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //line wise level order reversal

    while(q.size() > 0){
        Node* current =  q.front();
        q.pop();

        if(current == NULL){ //line wise level order reversal
            if(!q.empty()){
                cout<< endl;
                q.push(NULL);
                continue;
            
            }else{
                break;
            

            }
        }

        cout << current->data << " ";
        if(current->left != NULL){
            q.push(current->left);
        }
        if(current->right != NULL){
            q.push(current->right);
        }
    }
    cout<< endl;
}
int main(){
    vector<int> preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    Node* root = buildTree(preorder);
    // cout << root->data <<endl;
    // cout << root->left->data <<endl;
    // cout << root->right->data <<endl;
    // printPreorder(root->left);
    // printPreorder(root->right);
    // printPreorder(root);
    // cout<< endl;
    // inOrder(root);
    // postOrder(root);
    levelOrder(root);
    // cout<< endl;

    return 0;

}