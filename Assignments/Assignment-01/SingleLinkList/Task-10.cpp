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

// Task 10: swap every two consecutive tasks
void swapPairs(Node* h) {
    for (; h && h->next; h = h->next->next) {
        int t = h->data;
        h->data = h->next->data;
        h->next->data = t;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    Node* h = make(a, 6);
    cout << "Input: "; show(h);
    swapPairs(h);
    cout << "Output: "; show(h);
    return 0;
}