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

// Function to delete even or odd valued nodes
// deleteEven = true  → delete nodes with even data
// deleteEven = false → delete nodes with odd data
void deleteEvenOddNodes(Node*& head, bool deleteEven) {
    
    // First check and delete from the beginning (head)
    while (head != nullptr) {
        bool isEven = (head->data % 2 == 0);
        
        if ((deleteEven && isEven) || (!deleteEven && !isEven)) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        } else {
            break;
        }
    }
    
    if (head == nullptr) return;
    
    // Now delete from the rest of the list
    Node* current = head;
    while (current->next != nullptr) {
        bool isEven = (current->next->data % 2 == 0);
        
        if ((deleteEven && isEven) || (!deleteEven && !isEven)) {
            Node* toDelete = current->next;
            current->next = current->next->next;
            delete toDelete;
        } else {
            current = current->next;
        }
    }
}

int main() {
    // Creating a sample list: 1 → 2 → 3 → 4 → 5 → 6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    
    cout << "Original List: ";
    printList(head);
    
    // Delete even valued nodes
    deleteEvenOddNodes(head, true);
    
    cout << "After deleting even valued nodes: ";
    printList(head);
    
    return 0;
}