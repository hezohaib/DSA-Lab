//Reverse Display (Loop + Recursive).
#include <iostream>
using namespace std;

// structure for linked list node
struct Node {
    int data;
    Node* next;
};
Node* head = NULL; // global head pointer

// function to insert a new node at the end
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

// function to display the original linked list
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// function to print linked list in reverse using loops
void reverseLoop() {
    int count = 0;
    Node* temp = head;

    // count total number of nodes
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Reverse using Loop: ";
    // iterate backwards to print each element from last to first
    for (int i = count - 1; i >= 0; i--) {
        temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        cout << temp->data << " -> ";
    }
    cout << "NULL" << endl;
}

// function to print linked list in reverse using recursion
void reverseRecursive(Node* node) {
    // base case: stop when list ends
    if (node == NULL)
        return;

    // recursive call to reach the last node
    reverseRecursive(node->next);
    
    // print current node data while backtracking
    cout << node->data << " -> ";
}

int main() {
    // inserting elements into the list
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    // display original list
    cout << "Original List: ";
    display();

    // print reversed list using iterative method
    reverseLoop();

    // print reversed list using recursive method
    cout << "Reverse using Recursion: ";
    reverseRecursive(head);
    cout << "NULL" << endl;

    return 0;
}