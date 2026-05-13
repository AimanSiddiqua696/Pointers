#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

// Basic Node Structure
struct Node {
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// --- CORE FUNCTIONS ---

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

Node* findMin(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;
    if (key < root->data) root->left = deleteNode(root->left, key);
    else if (key > root->data) root->right = deleteNode(root->right, key);
    else {
        if (!root->left) { Node* temp = root->right; delete root; return temp; }
        else if (!root->right) { Node* temp = root->left; delete root; return temp; }
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// --- TASK FUNCTIONS ---

// Task 2 & 3: Validation and Violations
int violations = 0;
bool isBST(Node* root, long min, long max) {
    if (!root) return true;
    if (root->data <= min || root->data >= max) {
        violations++; 
        return false;
    }
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

// Task 4: kth Smallest
int kCount = 0;
void findKthSmallest(Node* root, int k) {
    if (!root || kCount >= k) return;
    findKthSmallest(root->left, k);
    kCount++;
    if (kCount == k) {
        cout << root->data;
        return;
    }
    findKthSmallest(root->right, k);
}

// Task 5: LCA
Node* getLCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data > n1 && root->data > n2) return getLCA(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return getLCA(root->right, n1, n2);
    return root;
}

// Task 6: Sorted Array to Balanced BST
Node* arrayToBST(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);
    root->left = arrayToBST(arr, start, mid - 1);
    root->right = arrayToBST(arr, mid + 1, end);
    return root;
}

// Task 7: Height
int getHeight(Node* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// Task 8: Identical Check
bool areIdentical(Node* r1, Node* r2) {
    if (!r1 && !r2) return true;
    if (!r1 || !r2) return false;
    return (r1->data == r2->data) && areIdentical(r1->left, r2->left) && areIdentical(r1->right, r2->right);
}

int main() {
    // Task 1: Create and Delete
    Node* root = NULL;
    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int v : values) root = insert(root, v);

    cout << "Initial Tree: "; inorder(root); cout << endl;

    root = deleteNode(root, 20); // Leaf
    cout << "After deleting 20 (Leaf): "; inorder(root); cout << endl;

    root = deleteNode(root, 50); // Two children
    cout << "After deleting 50 (Root/2 children): "; inorder(root); cout << endl;

    // Task 2 & 3
    violations = 0;
    cout << "\nIs valid BST? " << (isBST(root, LONG_MIN, LONG_MAX) ? "Yes" : "No");
    cout << "\nViolations found: " << violations << endl;

    // Task 4
    cout << "3rd Smallest element: ";
    kCount = 0;
    findKthSmallest(root, 3);
    cout << endl;

    // Task 5
    Node* lca = getLCA(root, 40, 60);
    if(lca) cout << "LCA of 40 and 60: " << lca->data << endl;

    // Task 6
    int sortedArr[] = {10, 20, 30, 40, 50, 60, 70};
    Node* balancedRoot = arrayToBST(sortedArr, 0, 6);
    cout << "Balanced BST from Array (Inorder): "; inorder(balancedRoot); cout << endl;

    // Task 7
    cout << "Height of Balanced BST: " << getHeight(balancedRoot) << endl;

    return 0;
}