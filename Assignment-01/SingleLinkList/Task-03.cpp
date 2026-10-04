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

// Task 3: remove duplicate contacts
void removeDuplicates(Node* h) {
    for (; h; h = h->next) {
        Node* p = h;
        while (p->next) {
            if (p->next->data == h->data) {
                Node* d = p->next;
                p->next = d->next;
                delete d;
            } else p = p->next;
        }
    }
}

int main() {
    int a[] = {10, 20, 10, 30, 20, 40};
    Node* h = make(a, 6);
    cout << "Before: "; show(h);
    removeDuplicates(h);
    cout << "After: "; show(h);
    return 0;
}