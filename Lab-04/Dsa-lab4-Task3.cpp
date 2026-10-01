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

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to delete all even positioned nodes
void deleteEvenPositionedNodes(Node*& head) {
    
    if (head == nullptr) return;
    
    Node* current = head;
    Node* prev = nullptr;
    int position = 1;
    
    while (current != nullptr) {
        
        if (position % 2 == 0) {
            // Even position → delete this node
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                // This case is rare because head is position 1 (odd)
                head = current->next;
            }
            
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        } 
        else {
            // Odd position → keep the node
            prev = current;
            current = current->next;
        }
        
        position++;
    }
}

int main() {
    // Creating sample list: 10 → 20 → 30 → 40 → 50 → 60
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    head->next->next->next->next->next = new Node(60);
    
    cout << "Original List: ";
    printList(head);
    
    deleteEvenPositionedNodes(head);
    
    cout << "After deleting even positioned nodes: ";
    printList(head);
    
    return 0;
}