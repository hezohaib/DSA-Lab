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

// normal in order traversal, used to show the tree
void inOrder(Node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

// finds the smallest value in a tree (keep going left)
Node* findMin(Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// deletes a node from the BST and returns the new root
Node* deleteNode(Node* root, int key) {
    // reached the end without finding the value
    if (root == NULL) {
        cout << key << " not found" << endl;
        return NULL;
    }

    // first search for the node to delete
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // case 1: node has no child, just remove it
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // case 2: node has only right child, right child takes its place
        if (root->left == NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // case 2: node has only left child, left child takes its place
        if (root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // case 3: node has both children
        // copy the smallest value of right subtree here, then delete that value
        Node* successor = findMin(root->right);
        root->data = successor->data;
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
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

    cout << "Tree (In Order): ";
    inOrder(root);
    cout << endl;

    // keep deleting until the user says no
    char again;
    do {
        cout << "Enter value to delete: ";
        cin >> value;
        root = deleteNode(root, value);
        cout << "Tree after deletion: ";
        inOrder(root);
        cout << endl;
        cout << "Delete another? (y/n): ";
        cin >> again;
    } while (again == 'y' || again == 'Y');

    return 0;
}