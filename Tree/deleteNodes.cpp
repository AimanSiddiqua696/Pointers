#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    // Insert Node
    Node* insert(Node* root, int value) {
        if (root == NULL) {
            return new Node(value);
        }

        if (value < root->data) {
            root->left = insert(root->left, value);
        }
        else {
            root->right = insert(root->right, value);
        }

        return root;
    }

    // Inorder Traversal
    void inorder(Node* root) {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    // Find Minimum Node
    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // Delete Node
    Node* deleteNode(Node* root, int value) {

        if (root == NULL)
            return NULL;

        if (value < root->data) {
            root->left = deleteNode(root->left, value);
        }

        else if (value > root->data) {
            root->right = deleteNode(root->right, value);
        }

        else {

            // Case 1: Leaf Node
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Case 2: One Child
            else if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }

            else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Two Children
            else {
                Node* temp = findMin(root->right);

                root->data = temp->data;

                root->right = deleteNode(root->right, temp->data);
            }
        }

        return root;
    }
};

int main() {

    BST tree;

    int values[] = {50,30,70,20,40,60,80};

    for (int i = 0; i < 7; i++) {
        tree.root = tree.insert(tree.root, values[i]);
    }

    cout << "Original BST: ";
    tree.inorder(tree.root);

    // Delete Leaf Node
    tree.root = tree.deleteNode(tree.root, 20);

    cout << "\nAfter deleting leaf node 20: ";
    tree.inorder(tree.root);

    // Delete Node with One Child
    tree.root = tree.deleteNode(tree.root, 30);

    cout << "\nAfter deleting node with one child 30: ";
    tree.inorder(tree.root);

    // Delete Node with Two Children
    tree.root = tree.deleteNode(tree.root, 70);

    cout << "\nAfter deleting node with two children 70: ";
    tree.inorder(tree.root);

    return 0;
}