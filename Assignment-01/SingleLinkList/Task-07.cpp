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

// Helper: reverses the first k nodes of the list
Node* reverseK(Node* h, int k) {
    Node *prev = NULL, *cur = h;
    while (k-- > 0 && cur) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    h->next = cur;
    return prev;
}

// Task 7: reverse first half and second half separately
Node* reverseHalves(Node* h) {
    int n = 0;
    for (Node* t = h; t; t = t->next) n++;
    if (n < 2) return h;
    Node* old = h;
    Node* newHead = reverseK(h, n / 2);
    old->next = reverseK(old->next, n - n / 2);
    return newHead;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Node* h = make(a, 8);
    cout << "Before: "; show(h);
    h = reverseHalves(h);
    cout << "After: "; show(h);
    return 0;
}