#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

int height(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int balanceFactor(Node *n)
{
    if (n == NULL)
        return 0;
    return height(n->left) - height(n->right);
}

Node *createNode(int value)
{
    Node *n = new Node;
    n->data = value;
    n->left = n->right = NULL;
    n->height = 1;
    return n;
}

// LL case
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *temp = x->right;

    x->right = y;
    y->left = temp;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    return x;
}

// RR case
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *temp = y->left;

    y->left = x;
    x->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    return y;
}

Node *insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));
    int bf = balanceFactor(root);

    // LL
    if (bf > 1 && value < root->left->data)
    {
        cout << "LL rotation at " << root->data << endl;
        return rightRotate(root);
    }
    // RR
    if (bf < -1 && value > root->right->data)
    {
        cout << "RR rotation at " << root->data << endl;
        return leftRotate(root);
    }
    // LR
    if (bf > 1 && value > root->left->data)
    {
        cout << "LR rotation at " << root->data << endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RL
    if (bf < -1 && value < root->right->data)
    {
        cout << "RL rotation at " << root->data << endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, value;

    cout << "How many nodes? ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> value;
        root = insert(root, value);
    }

    cout << "In Order: ";
    inOrder(root);
    cout << endl;
    cout << "Root of AVL tree: " << root->data << endl;

    return 0;
}