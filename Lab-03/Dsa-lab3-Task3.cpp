#include <iostream>
using namespace std;

// Node structure for Singly Linked List
struct SNode {
    int data;       // Data stored in the node
    SNode *next;    // Pointer to the next node
};

// Node structure for Doubly Linked List
struct DNode {
    int data;       // Data stored in the node
    DNode *prev;    // Pointer to the previous node
    DNode *next;    // Pointer to the next node
};

// Global pointers
SNode *sHead = NULL;    // Head of the singly linked list
DNode *dHead = NULL;    // Head of the doubly linked list
DNode *dTail = NULL;    // Tail of the doubly linked list

// Insert a new node at the end of the singly linked list
void insertSingly(int val) {
    SNode *newNode = new SNode;     // Create a new node
    newNode->data = val;            // Assign the value
    newNode->next = NULL;           // New node will be the last node

    if (sHead == NULL) {
        // List is empty → new node becomes the head
        sHead = newNode;
    }
    else {
        // Traverse to the last node
        SNode *temp = sHead;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;       // Link the new node at the end
    }
}

// Display the singly linked list
void displaySingly() {
    SNode *temp = sHead;            // Start from the head

    while (temp != NULL) {
        cout << temp->data;

        // Print the arrow only if there is a next node
        if (temp->next != NULL)
            cout << " -> ";

        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}

// Insert a new node at the end of the doubly linked list
void insertDoubly(int val) {
    DNode *newNode = new DNode;     // Create a new node
    newNode->data = val;            // Assign the value
    newNode->prev = NULL;           // Initially no previous node
    newNode->next = NULL;           // Initially no next node

    if (dHead == NULL) {
        // List is empty → new node becomes both head and tail
        dHead = newNode;
        dTail = newNode;
    }
    else {
        // Link the new node after the current tail
        dTail->next = newNode;
        newNode->prev = dTail;
        dTail = newNode;            // Update tail to the new node
    }
}

// Display the doubly linked list
void displayDoubly() {
    DNode *temp = dHead;            // Start from the head

    while (temp != NULL) {
        cout << temp->data;

        // Print the bidirectional link only if there is a next node
        if (temp->next != NULL)
            cout << " <-> ";

        temp = temp->next;          // Move to the next node
    }
    cout << endl;
}

// Convert the singly linked list into a doubly linked list
void convert() {
    SNode *temp = sHead;            // Start from the head of singly list

    // Traverse the singly list and insert each value into the doubly list
    while (temp != NULL) {
        insertDoubly(temp->data);   // Insert current data into doubly list
        temp = temp->next;          // Move to the next node in singly list
    }
}

int main() {
    // Insert some values into the singly linked list
    insertSingly(5);
    insertSingly(15);
    insertSingly(25);
    insertSingly(35);
    insertSingly(45);

    cout << "Singly Linked List: ";
    displaySingly();

    // Convert singly linked list to doubly linked list
    convert();

    cout << "Doubly Linked List: ";
    displayDoubly();

    return 0;
}