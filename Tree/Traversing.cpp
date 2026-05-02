#include <iostream>
using namespace std;

// Node structure
struct Node {
    char data;
    Node* left;
    Node* right;
};

// Create node
Node* createNode(char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Preorder Traversal
void preorder(Node* root) {
    if (root == NULL)
        return;

    cout << root->data << " ";   // Node
    preorder(root->left);        // Left
    preorder(root->right);       // Right
}

// Inorder Traversal
void inorder(Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);         // Left
    cout << root->data << " ";   // Node
    inorder(root->right);        // Right
}

// Postorder Traversal
void postorder(Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);       // Left
    postorder(root->right);      // Right
    cout << root->data << " ";   // Node
}

int main() {
    // Create tree
    Node* A = createNode('A');
    Node* B = createNode('B');
    Node* C = createNode('C');
    Node* D = createNode('D');
    Node* E = createNode('E');
    Node* F = createNode('F');

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = E;
    C->right = F;

    cout << "Preorder: ";
    preorder(A);

    cout << "\nInorder: ";
    inorder(A);

    cout << "\nPostorder: ";
    postorder(A);

    return 0;
}