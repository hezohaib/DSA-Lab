#include <iostream>
using namespace std;

// Node structure: contains data and a pointer to the next node
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

// Searches for oldValue in the list and replaces it with newVal
void replaceValue(Node* head, int oldVal, int newVal) {
    Node* temp = head;
    while (temp != NULL) {      // Traverse until the end of the list
        if (temp->data == oldVal)     // If the value matches
            temp->data = newVal;      // Replace it
        temp = temp->next;            // Move to the next node
    }
}

// Prints the entire list
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

    // Create a list from 1 to 10
    for (int i = 1; i <= 10; i++)
        head = insertEnd(head, i);

    cout << "Original list: ";
    printList(head);

    // Replace 3 with 30 and 7 with 70
    replaceValue(head, 3, 30);
    replaceValue(head, 7, 70);

    cout << "After replace: ";
    printList(head);

    return 0;
}