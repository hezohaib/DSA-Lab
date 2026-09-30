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

// Reverse the doubly linked list
void reverse() {
    // Nothing to reverse if list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return;

    Node *current = head;
    Node *temp = NULL;

    // Traverse the list and swap prev and next pointers of each node
    while (current != NULL) {
        // Swap the prev and next pointers
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // Move to the next node (which is now stored in prev after swapping)
        current = current->prev;
    }

    // After reversing, swap head and tail
    temp = head;
    head = tail;
    tail = temp;
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

    // Reverse the list
    reverse();

    cout << "After Reverse: ";
    display();

    return 0;
}