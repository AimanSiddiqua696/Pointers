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

int countViolations(Node* root, int min, int max) {

    if (root == NULL)
        return 0;

    int count = 0;

    if (root->data <= min || root->data >= max)
        count++;

    count += countViolations(root->left, min, root->data);

    count += countViolations(root->right, root->data, max);

    return count;
}

int main() {

    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->right->left = new Node(10);

    cout << "Violations = "
         << countViolations(root, INT_MIN, INT_MAX);

    return 0;
}