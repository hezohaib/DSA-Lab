#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class Deque {
    Node* front;
    Node* rear;

public:
    Deque() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void insertFront(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = front;

        if (isEmpty())
            rear = newNode;
        else
            front->prev = newNode;
        front = newNode;
    }

    void insertRear(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = rear;

        if (isEmpty())
            front = newNode;
        else
            rear->next = newNode;
        rear = newNode;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == NULL)
            rear = NULL;
        else
            front->prev = NULL;
        cout << temp->data << " removed from front" << endl;
        delete temp;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = rear;
        rear = rear->prev;
        if (rear == NULL)
            front = NULL;
        else
            rear->next = NULL;
        cout << temp->data << " removed from rear" << endl;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Deque d;
    int choice, value;

    do {
        cout << "\n1. Insert at front\n2. Insert at rear\n3. Delete from front\n4. Delete from rear\n";
        cout << "5. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            d.insertFront(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            d.insertRear(value);
            break;
        case 3:
            d.deleteFront();
            break;
        case 4:
            d.deleteRear();
            break;
        case 5:
            d.display();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    return 0;
}