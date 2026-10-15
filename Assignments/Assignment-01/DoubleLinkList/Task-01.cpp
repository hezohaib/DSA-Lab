#include <iostream>
#include <string>
using namespace std;

struct DNode { string data; DNode *prev, *next; };

// Helper: builds a doubly linked list from an array
DNode* makeD(string a[], int n) {
    DNode *head = NULL, *tail = NULL;
    for (int i = 0; i < n; i++) {
        DNode* t = new DNode{a[i], tail, NULL};
        if (!head) head = t; else tail->next = t;
        tail = t;
    }
    return head;
}

// Helper: returns the last node
DNode* tailOf(DNode* h) {
    while (h->next) h = h->next;
    return h;
}

// Helper: prints the list forward
void showD(DNode* h) {
    for (; h; h = h->next) cout << h->data << " ";
    cout << endl;
}

// Helper: swaps data of two nodes (addresses stay same)
void sw(DNode* a, DNode* b) {
    string t = a->data;
    a->data = b->data;
    b->data = t;
}

// Task 1: swap first desk with last, second with second-last, ...
void swapDesks(DNode* h) {
    DNode *l = h, *r = tailOf(h);
    while (l != r && l->prev != r) {
        sw(l, r);
        l = l->next;
        r = r->prev;
    }
}

int main() {
    string names[] = {"Alice", "Bob", "Charlie", "Dana", "Eva", "Frank"};
    DNode* h = makeD(names, 6);
    cout << "Before: "; showD(h);
    swapDesks(h);
    cout << "After: "; showD(h);
    return 0;
}