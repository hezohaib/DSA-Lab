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

// Pre Order with right priority: Node, Right, Left
void preOrderNRL(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderNRL(root->right);
    preOrderNRL(root->left);
}

// Post Order with right priority: Right, Left, Node
void postOrderRLN(Node* root) {
    if (root == NULL)
        return;
    postOrderRLN(root->right);
    postOrderRLN(root->left);
    cout << root->data << " ";
}

// In Order with right priority: Right, Node, Left
void inOrderRNL(Node* root) {
    if (root == NULL)
        return;
    inOrderRNL(root->right);
    cout << root->data << " ";
    inOrderRNL(root->left);
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

    // calling all three traversals
    cout << "Pre Order (NRL): ";
    preOrderNRL(root);
    cout << endl;

    cout << "Post Order (RLN): ";
    postOrderRLN(root);
    cout << endl;

    cout << "In Order (RNL): ";
    inOrderRNL(root);
    cout << endl;

    return 0;
}