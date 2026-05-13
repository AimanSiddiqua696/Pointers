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

void kthSmallest(Node* root, int k, int &count) {

    if (root == NULL)
        return;

    kthSmallest(root->left, k, count);

    count++;

    if (count == k) {
        cout << "Kth Smallest = " << root->data;
        return;
    }

    kthSmallest(root->right, k, count);
}

int main() {

    Node* root = new Node(50);

    root->left = new Node(30);
    root->right = new Node(70);

    root->left->left = new Node(20);
    root->left->right = new Node(40);

    root->right->left = new Node(60);
    root->right->right = new Node(80);

    int k = 3;
    int count = 0;

    kthSmallest(root, k, count);

    return 0;
}