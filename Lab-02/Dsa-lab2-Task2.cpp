//Merging Two Linked Lists.
#include <iostream>
using namespace std;

// structure definition for linked list node
struct Node {
    int data;
    Node* next;
};

// function to append a new node at the end
void insert(Node*& head, int value) {
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

// function to print all nodes of a list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// function to concatenate two linked lists into a new one
Node* merge(Node* head1, Node* head2) {
    Node* result = NULL;

    // copy elements from first list
    Node* temp = head1;
    while (temp != NULL) {
        insert(result, temp->data);
        temp = temp->next;
    }

    // copy elements from second list
    temp = head2;
    while (temp != NULL) {
        insert(result, temp->data);
        temp = temp->next;
    }

    return result;
}

int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // populate first list
    insert(list1, 10);
    insert(list1, 20);
    insert(list1, 30);

    // populate second list
    insert(list2, 100);
    insert(list2, 200);
    insert(list2, 300);

    // display individual lists
    cout << "List 1: ";
    display(list1);

    cout << "List 2: ";
    display(list2);

    // merge lists and display result
    Node* merged = merge(list1, list2);

    cout << "Merged List: ";
    display(merged);

    return 0;
}