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

// Task 4: detect loop using slow and fast pointers
bool hasLoop(Node* h) {
    Node *slow = h, *fast = h;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    int a[] = {1, 2, 3, 4, 5};
    Node* h = make(a, 5);
    cout << "Loop (no loop created): " << (hasLoop(h) ? "Yes" : "No") << endl;

    h->next->next->next->next->next = h->next;   // last node points to 2nd node
    cout << "Loop (after creating loop): " << (hasLoop(h) ? "Yes" : "No") << endl;
    return 0;
}