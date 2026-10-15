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

// Task 9: delete all books with the given ID (start, middle, end, multiple times)
void deleteAll(Node*& h, int key) {
    while (h && h->data == key) {        // key at the beginning
        Node* d = h;
        h = h->next;
        delete d;
    }
    for (Node* c = h; c && c->next;) {   // key in middle or end
        if (c->next->data == key) {
            Node* d = c->next;
            c->next = d->next;
            delete d;
        } else c = c->next;
    }
}

int main() {
    int a[] = {5, 2, 5, 7, 5, 9, 5};
    Node* h = make(a, 7);
    cout << "Catalog before: "; show(h);
    deleteAll(h, 5);
    cout << "Catalog after deleting ID 5: "; show(h);
    return 0;
}