#include <iostream>
using namespace std;

// structure of one tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// inserts a value in the BST and returns the root
Node* insert(Node* root, int value) {
    // empty spot found, so create a new node here
    if (root == NULL) {
        Node* n = new Node;
        n->data = value;
        n->left = n->right = NULL;
        return n;
    }
    // smaller values go left, bigger values go right
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// prints every leaf node and returns how many leaves there are
int printLeaves(Node* root) {
    // empty tree has no leaves
    if (root == NULL)
        return 0;

    // a node with no left and no right child is a leaf
    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " ";
        return 1;
    }

    // otherwise add up the leaves of both subtrees
    return printLeaves(root->left) + printLeaves(root->right);
}

int main() {
    Node* root = NULL;
    int n, value;

    // taking input from user to build the tree
    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    // print the leaves and show the total count
    cout << "Leaf nodes: ";
    int count = printLeaves(root);
    cout << "\nTotal leaf nodes = " << count << endl;

    return 0;
}