#include <iostream>
using namespace std;

struct Node { int data; Node* next; };

// Task 1: Josephus problem - returns the position that survives
int josephus(int n, int m) {
    Node* head = new Node{1, NULL};
    Node* tail = head;
    for (int i = 2; i <= n; i++) { tail->next = new Node{i, NULL}; tail = tail->next; }
    tail->next = head;                       // make the list circular

    Node *prev = tail, *cur = head;
    cout << "Killed order: ";
    while (cur->next != cur) {
        for (int i = 1; i < m; i++) { prev = cur; cur = cur->next; }   // skip m-1 persons
        cout << cur->data << " ";
        prev->next = cur->next;              // kill the m-th person
        delete cur;
        cur = prev->next;
    }
    cout << endl;
    return cur->data;
}

int main() {
    int n = 7, m = 3;
    cout << "N = " << n << ", M = " << m << endl;
    int safe = josephus(n, m);
    cout << "Safe position to survive: " << safe << endl;
    return 0;
}