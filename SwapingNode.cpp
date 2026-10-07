#include <iostream>
using namespace std;

// structure of node 
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

    temp->next = newNode;       // last node ko naye node se jodo
    return head;
}

// List mein a ko b se aur b ko a se replace karta hai (ek hi loop mein)
void swapValues(Node* head, int a, int b) {
    Node* temp = head;
    while (temp != NULL) {              // list ke end tak chalna ha
        if (temp->data == a)            // agar value a hay
            temp->data = b;             // to usay b bana do
        else if (temp->data == b)       // warna agar value b hay
            temp->data = a;             // to usay a bana do
        temp = temp->next;              // agle node par jao
    }
}

// Poori list print karwa rhy hain 
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

    // 1 se 10 tak list banao
    for (int i = 1; i <= 10; i++)
        head = insertEnd(head, i);

    cout << "Original list: ";
    printList(head);

    // 3 ko 7 se aur 7 ko 3 se replace karo
    swapValues(head, 3, 7);

    cout << "After replace: ";
    printList(head);

    return 0;
}