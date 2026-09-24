#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Display list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Task 1: Display in reverse order (without changing list)
void displayReverse(Node* head) {
    if (head == NULL) return;
    displayReverse(head->next);
    cout << head->data << " ";
}

// Task 2: Reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = NULL;

    while (curr != NULL) {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

// Task 3 & 8: Remove duplicates
void removeDuplicates(Node* head) {
    if (head == NULL) return;

    Node* curr = head;
    while (curr != NULL) {
        Node* temp = curr;
        while (temp->next != NULL) {
            if (temp->next->data == curr->data) {
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

// Task 4: Detect loop
bool hasLoop(Node* head) {
    if (head == NULL) return false;

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

// Task 5: Find middle node (left one if even)
Node* findMiddle(Node* head) {
    if (head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Task 6: Separate even and odd
void separateEvenOdd(Node* head, Node*& evenHead, Node*& oddHead) {
    evenHead = NULL;
    oddHead = NULL;
    Node* evenTail = NULL;
    Node* oddTail = NULL;

    Node* curr = head;
    while (curr != NULL) {
        Node* nextNode = curr->next;
        curr->next = NULL;

        if (curr->data % 2 == 0) {
            if (evenHead == NULL) {
                evenHead = curr;
                evenTail = curr;
            } else {
                evenTail->next = curr;
                evenTail = curr;
            }
        } else {
            if (oddHead == NULL) {
                oddHead = curr;
                oddTail = curr;
            } else {
                oddTail->next = curr;
                oddTail = curr;
            }
        }
        curr = nextNode;
    }
}

// Task 7: Reverse first half and second half
Node* reverseHalves(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    // Find middle
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Break the list
    prev->next = NULL;

    // Reverse both halves
    Node* first = reverseList(head);
    Node* second = reverseList(slow);

    // Join them
    Node* temp = first;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = second;

    return first;
}

// Task 9: Delete all occurrences of a key
Node* deleteAll(Node* head, int key) {
    while (head != NULL && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    if (head == NULL) return NULL;

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->next->data == key) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    return head;
}

// Task 10: Swap pairs
Node* swapPairs(Node* head) {
    if (head == NULL || head->next == NULL) return head;

    Node* newHead = head->next;
    Node* prev = NULL;
    Node* curr = head;

    while (curr != NULL && curr->next != NULL) {
        Node* nextPair = curr->next->next;
        Node* second = curr->next;

        second->next = curr;
        curr->next = nextPair;

        if (prev != NULL) {
            prev->next = second;
        }

        prev = curr;
        curr = nextPair;
    }
    return newHead;
}

int main() {
    Node* head = NULL;

    // Creating list: 1 2 3 4 5 6 7 8
    for (int i = 1; i <= 8; i++) {
        insertEnd(head, i);
    }

    cout << "Original List: ";
    display(head);

    cout << "Reverse Display: ";
    displayReverse(head);
    cout << endl;

    head = reverseList(head);
    cout << "After Reversing List: ";
    display(head);

    // Reset list for other tests
    head = NULL;
    for (int i = 1; i <= 8; i++) {
        insertEnd(head, i);
    }

    head = reverseHalves(head);
    cout << "After Reversing Halves: ";
    display(head);

    head = NULL;
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);
    insertEnd(head, 6);

    head = swapPairs(head);
    cout << "After Swap Pairs: ";
    display(head);

    return 0;
}