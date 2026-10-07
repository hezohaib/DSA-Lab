#include <iostream>
using namespace std;

// Node ka structure: data aur agle node ka pointer
struct Node {
    int data;
    Node* next;
};

// List ke end mein naya node add karta hai
Node* insertEnd(Node* head, int value) {
    Node* newNode = new Node;   // naya node banao
    newNode->data = value;      // value store karo
    newNode->next = NULL;       // abhi ye last node hai

    if (head == NULL)           // agar list khali hai
        return newNode;         // to naya node hi head ban jayega

    Node* temp = head;
    while (temp->next != NULL)  // last node tak jao
        temp = temp->next;

    temp->next = newNode;       // last node ko naye node se jor do
    return head;
}

// List mein oldValue ko dhoond kar newValue se replace karta ha
void replaceValue(Node* head, int oldVal, int newVal) {
    Node* temp = head;
    while (temp != NULL) {              // list ke end tak chalo
        if (temp->data == oldVal)       // agar value match ho gayi
            temp->data = newVal;        // to usay replace kar do
        temp = temp->next;              // agle node par jao
    }
}

// Poori list print karta hai
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

    // 1 se 10 tak list bana rha ha

    for (int i = 1; i <= 10; i++)
        head = insertEnd(head, i);

    cout << "Original list: ";
    printList(head);

    // 3 ko 30 aur 7 ko 70 se replace karo
    replaceValue(head, 3, 30);
    replaceValue(head, 7, 70);

    cout << "After replace: ";
    printList(head);

    return 0;
}