#include <iostream>
using namespace std;

// Structure of a linked list node 
struct Node {
    int data;
    Node* next;
};

// Adds a new node at the end of the list
Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node;   // Create a new node
    newNode->data = value;      // Store the value
    newNode->next = NULL;       // This is currently the last node

    if (head == NULL)           // If the list is empty
        return newNode;         // The new node becomes the head

    Node* temp = head;
    while (temp->next != NULL)  // Traverse to the last node
        temp = temp->next;

    temp->next = newNode;       // Link the last node to the new node
    return head;
}

// Swaps occurrences of value 'a' with 'b' and 'b' with 'a' in a single traversal
void swapValues(Node* head, int a, int b) {
    Node* temp = head;
    while (temp != NULL) {      // Traverse until the end of the list
        if (temp->data == a)    // If the value is 'a'
            temp->data = b;     // Change it to 'b'
        else if (temp->data == b) // Otherwise, if the value is 'b'
            temp->data = a;     // Change it to 'a'
        temp = temp->next;      // Move to the next node
    }
}

// Prints the entire linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Create a linked list with numbers from 1 to 10
    for (int i = 1; i <= 10; i++)
        head = insertEnd(head, i);

    cout << "Original list: ";
    printList(head);

    // Swap values 3 and 7
    swapValues(head, 3, 7);

    cout << "After replace: ";
    printList(head);

    return 0;
}