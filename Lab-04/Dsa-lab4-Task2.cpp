#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function that solves Josephus problem
// n = total number of people
// k = every k-th person is eliminated
int josephus(int n, int k) {
    
    if (n <= 0 || k <= 0) {
        cout << "Invalid input!" << endl;
        return -1;
    }
    
    // Create circular linked list with numbers 1 to n
    Node* head = new Node(1);
    Node* prev = head;
    
    for (int i = 2; i <= n; i++) {
        prev->next = new Node(i);
        prev = prev->next;
    }
    prev->next = head;   // make it circular
    
    Node* current = head;
    Node* last = prev;   // node just before current
    
    // Keep eliminating until only one node remains
    while (current->next != current) {
        
        // Move k-1 steps forward
        for (int count = 1; count < k; count++) {
            last = current;
            current = current->next;
        }
        
        // Eliminate the current node
        cout << "Eliminated: " << current->data << endl;
        last->next = current->next;
        
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    
    int survivor = current->data;
    delete current;   // free the last remaining node
    
    return survivor;
}

int main() {
    int n = 7;   // total people
    int k = 3;   // every 3rd person
    
    cout << "Total people (n) = " << n << endl;
    cout << "Elimination count (k) = " << k << endl;
    cout << endl;
    
    int result = josephus(n, k);
    
    cout << "\nThe survivor is: " << result << endl;
    
    return 0;
}