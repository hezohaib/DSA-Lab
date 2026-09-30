#include <iostream>
using namespace std;

// Node structure for doubly linked list
struct Node {
    int data;       // Data stored in the node
    Node *prev;     // Pointer to the previous node
    Node *next;     // Pointer to the next node
};

// Global pointers to keep track of the list
Node *head = NULL;  // Points to the first node
Node *tail = NULL;  // Points to the last node

// Insert a new node at the end of the list
void insert(int val) {
    Node *newNode = new Node;   // Create a new node
    newNode->data = val;        // Assign the value
    newNode->prev = NULL;       // Initially no previous node
    newNode->next = NULL;       // Initially no next node

    if (head == NULL) {
        // List is empty → new node becomes both head and tail
        head = newNode;
        tail = newNode;
    }
    else {
        // Link the new node after the current tail
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;         // Update tail to the new node
    }
}

// Display the list from head to tail
void display() {
    Node *temp = head;          // Start from the head

    while (temp != NULL) {
        cout << temp->data;

        // Print the link only if there is a next node
        if (temp->next != NULL)
            cout << " <-> ";

        temp = temp->next;      // Move to the next node
    }
    cout << endl;
}

// Swap two nodes by their values (not just data)
void swapNodes(int val1, int val2) {
    // No need to swap if both values are the same
    if (val1 == val2)
        return;

    Node *node1 = NULL;         // Will store address of first node
    Node *node2 = NULL;         // Will store address of second node
    Node *temp = head;

    // Search for both nodes in the list
    while (temp != NULL) {
        if (temp->data == val1)
            node1 = temp;
        if (temp->data == val2)
            node2 = temp;
        temp = temp->next;
    }

    // If either value is not found
    if (node1 == NULL || node2 == NULL) {
        cout << "Value not found in list" << endl;
        return;
    }

    // Case 1: node1 is immediately before node2 (adjacent nodes)
    if (node1->next == node2) {
        node1->next = node2->next;
        node2->prev = node1->prev;

        if (node1->next != NULL)
            node1->next->prev = node1;
        if (node2->prev != NULL)
            node2->prev->next = node2;

        node2->next = node1;
        node1->prev = node2;
    }
    // Case 2: node2 is immediately before node1 (adjacent nodes, reverse order)
    else if (node2->next == node1) {
        node2->next = node1->next;
        node1->prev = node2->prev;

        if (node2->next != NULL)
            node2->next->prev = node2;
        if (node1->prev != NULL)
            node1->prev->next = node1;

        node1->next = node2;
        node2->prev = node1;
    }
    // Case 3: Nodes are not adjacent
    else {
        // Store neighbors of both nodes
        Node *p1 = node1->prev;     // Previous of node1
        Node *n1 = node1->next;     // Next of node1
        Node *p2 = node2->prev;     // Previous of node2
        Node *n2 = node2->next;     // Next of node2

        // Update links for node2's new position
        if (p1 != NULL)
            p1->next = node2;
        else
            head = node2;           // node1 was head → node2 becomes head

        if (n1 != NULL)
            n1->prev = node2;
        else
            tail = node2;           // node1 was tail → node2 becomes tail

        // Update links for node1's new position
        if (p2 != NULL)
            p2->next = node1;
        else
            head = node1;           // node2 was head → node1 becomes head

        if (n2 != NULL)
            n2->prev = node1;
        else
            tail = node1;           // node2 was tail → node1 becomes tail

        // Swap the prev and next pointers of the two nodes
        node1->prev = p2;
        node1->next = n2;
        node2->prev = p1;
        node2->next = n1;
    }

    cout << "Nodes swapped" << endl;
}

int main() {
    // Insert some values into the list
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    display();

    // Take two values from user to swap
    int a, b;
    cout << "Enter two values: ";
    cin >> a >> b;

    // Perform the swap
    swapNodes(a, b);

    cout << "After Swap: ";
    display();

    return 0;
}