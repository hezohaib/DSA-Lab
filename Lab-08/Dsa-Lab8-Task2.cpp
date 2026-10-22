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

    if (bf > 1 && value < root->left->data)
        return rightRotate(root);

    if (bf < -1 && value > root->right->data)
        return leftRotate(root);

    if (bf > 1 && value > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (bf < -1 && value < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

// level order traversal using a queue
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty" << endl;
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        Node *current = queue[front++];
        cout << current->data << " ";

        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    cout << endl;
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

    cout << "Level Order: ";
    levelOrder(root);

    return 0;
}