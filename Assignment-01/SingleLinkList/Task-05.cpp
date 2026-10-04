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

// Task 5: find middle friend (left one if count is even)
Node* middle(Node* h) {
    Node *slow = h, *fast = h;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    Node* h = make(a, 5);
    cout << "List: "; show(h);
    cout << "Middle (odd count): " << middle(h)->data << endl;

    h = make(a, 6);
    cout << "List: "; show(h);
    cout << "Middle (even count): " << middle(h)->data << endl;
    return 0;
}