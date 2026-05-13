#include <iostream>
#include <climits>
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

bool isBST(Node* root, int min, int max) {

    if (root == NULL)
        return true;

    if (root->data <= min || root->data >= max)
        return false;

    return isBST(root->left, min, root->data) &&
           isBST(root->right, root->data, max);
}

int main() {

    // Valid BST
    Node* root1 = new Node(40);
    root1->left = new Node(20);
    root1->right = new Node(60);

    // Invalid BST
    Node* root2 = new Node(40);
    root2->left = new Node(20);
    root2->right = new Node(60);
    root2->right->left = new Node(10);

    cout << "Valid BST Check: ";

    if (isBST(root1, INT_MIN, INT_MAX))
        cout << "Valid";
    else
        cout << "Invalid";

    cout << "\nInvalid BST Check: ";

    if (isBST(root2, INT_MIN, INT_MAX))
        cout << "Valid";
    else
        cout << "Invalid";

    return 0;
}