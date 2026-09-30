//Finding Multiple Occurrences.
#include <iostream>
using namespace std;

// structure for linked list node
struct Node {
    int data;
    Node* next;
};
Node* head = NULL; // global head pointer

// function to append new node at the end
void insert(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// function to print the linked list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// function to search and count all occurrences of a value
void findOccurrences(int value) {
    Node* temp = head;
    int count = 0; // tracks total occurrences
    int pos = 1;   // tracks node position (1-based index)

    cout << "Searching for " << value << ":" << endl;

    // traverse through entire list
    while (temp != NULL) {
        if (temp->data == value) {
            count++;
            cout << "Found at position " << pos << endl;
        }
        temp = temp->next;
        pos++;
    }

    // print summary result
    if (count == 0)
        cout << "Not found" << endl;
    else
        cout << "Total times found: " << count << endl;
}

int main() {
    // inserting values into the list (including duplicates)
    insert(10);
    insert(20);
    insert(30);
    insert(20);
    insert(40);
    insert(20);
    insert(50);

    // display initial list
    cout << "List: ";
    display();
    cout << endl;

    // test search for an existing element with duplicates
    findOccurrences(20);
    cout << endl;

    // test search for a non-existing element
    findOccurrences(99);

    return 0;
}