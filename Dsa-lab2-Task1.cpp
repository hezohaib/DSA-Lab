//Reverse Display (Loop + Recursive).
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
Node* head = NULL;

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
void display() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void reverseLoop() {
    int count = 0;
    Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    cout << "Reverse using Loop: ";
    for (int i = count - 1; i >= 0; i--) {
        temp = head;
        for (int j = 0; j < i; j++) {
            temp = temp->next;
        }
        cout << temp->data << " -> ";
    }
    cout << "NULL" << endl;
}
void reverseRecursive(Node* node) {
    if (node == NULL)
        return;

    reverseRecursive(node->next);
    cout << node->data << " -> ";
}
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);

    cout << "Original List: ";
    display();

    reverseLoop();

    cout << "Reverse using Recursion: ";
    reverseRecursive(head);
    cout << "NULL" << endl;

    return 0;
}