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

// Task 2: reverse the playlist by changing only the links
Node* reverse(Node* h) {
    Node *prev = NULL, *cur = h;
    while (cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    Node* h = make(a, 5);
    cout << "Original: "; show(h);
    h = reverse(h);
    cout << "Reversed: "; show(h);
    return 0;
}