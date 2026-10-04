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

// Task 6: split customers into even-price line and odd-price line
void splitEvenOdd(Node* h, Node*& even, Node*& odd) {
    Node *et = NULL, *ot = NULL;
    while (h) {
        Node* nxt = h->next;
        h->next = NULL;
        if (h->data % 2 == 0) {
            if (!even) even = h; else et->next = h;
            et = h;
        } else {
            if (!odd) odd = h; else ot->next = h;
            ot = h;
        }
        h = nxt;
    }
}

int main() {
    int a[] = {12, 5, 8, 7, 20, 3};
    Node* h = make(a, 6);
    cout << "All customers: "; show(h);
    Node *even = NULL, *odd = NULL;
    splitEvenOdd(h, even, odd);
    cout << "Even line: "; show(even);
    cout << "Odd line: "; show(odd);
    return 0;
}