//Finding Multiple Occurrences.
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
void findOccurrences(int value) {
    Node* temp = head;
    int count = 0;
    int pos = 1;

    cout << "Searching for " << value << ":" << endl;

    while (temp != NULL) {
        if (temp->data == value) {
            count++;
            cout << "Found at position " << pos << endl;
        }
        temp = temp->next;
        pos++;
    }

    if (count == 0)
        cout << "Not found" << endl;
    else
        cout << "Total times found: " << count << endl;
}
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(20);
    insert(40);
    insert(20);
    insert(50);

    cout << "List: ";
    display();
    cout << endl;

    findOccurrences(20);
    cout << endl;
    findOccurrences(99);

    return 0;
}