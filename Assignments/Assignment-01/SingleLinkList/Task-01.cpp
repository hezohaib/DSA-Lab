#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

// Helper: builds a list from an array
Node* make(int a[], int n) {
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        Node* t = new Node{a[i], NULL};
        if (!head) head = t; else tail->next = t;
        tail = t;
    }
    return head;
}

// Helper: prints the list
void show(Node* h) {
    for (; h; h = h->next) cout << h->data << " ";
    cout << endl;
}

// Task 1: display list in reverse order without changing the list
void printReverse(Node* h) {
    if (!h) return;
    printReverse(h->next);
    cout << h->data << " ";
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    Node* h = make(a, 5);
    cout << "Original: "; show(h);
    cout << "Reverse display: "; printReverse(h); cout << endl;
    cout << "List after: "; show(h);
    return 0;
}