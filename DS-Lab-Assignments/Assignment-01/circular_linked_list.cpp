#include <iostream>
#include <string>
using namespace std;

struct CNode {
    int data;               // for Josephus
    string name;            // for task scheduler
    int priority;
    string status;
    CNode* next;
};

// ========== Josephus Problem ==========
int josephus(int N, int M) {
    if (N <= 0) return -1;

    // Create circular list
    CNode* head = new CNode();
    head->data = 1;
    head->next = head;

    CNode* curr = head;
    for (int i = 2; i <= N; i++) {
        CNode* newNode = new CNode();
        newNode->data = i;
        newNode->next = head;
        curr->next = newNode;
        curr = newNode;
    }

    // Start killing
    CNode* p = head;
    while (p->next != p) {
        // Skip M-1 persons
        for (int i = 1; i < M - 1; i++) {
            p = p->next;
        }

        // Kill Mth person
        CNode* toDelete = p->next;
        p->next = toDelete->next;
        // cout << "Killed: " << toDelete->data << endl;
        delete toDelete;

        p = p->next;
    }

    int survivor = p->data;
    delete p;
    return survivor;
}

// ========== Task Scheduler ==========
class TaskScheduler {
private:
    CNode* head;

public:
    TaskScheduler() {
        head = NULL;
    }

    void addTask(string name, int priority, string status = "pending") {
        CNode* newNode = new CNode();
        newNode->name = name;
        newNode->priority = priority;
        newNode->status = status;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            head->next = head;
            return;
        }

        CNode* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }

    void removeTask(string name) {
        if (head == NULL) return;

        // Only one node
        if (head->next == head && head->name == name) {
            delete head;
            head = NULL;
            return;
        }

        CNode* curr = head;
        CNode* prev = NULL;

        do {
            if (curr->name == name) break;
            prev = curr;
            curr = curr->next;
        } while (curr != head);

        if (curr->name != name) {
            cout << "Task not found\n";
            return;
        }

        if (curr == head) {
            CNode* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        } else {
            prev->next = curr->next;
        }
        delete curr;
    }

    void displayAll() {
        if (head == NULL) {
            cout << "No tasks available\n";
            return;
        }

        CNode* temp = head;
        do {
            cout << "Name: " << temp->name
                 << " | Priority: " << temp->priority
                 << " | Status: " << temp->status << endl;
            temp = temp->next;
        } while (temp != head);
    }

    void updateStatus(string name, string newStatus) {
        if (head == NULL) return;

        CNode* temp = head;
        do {
            if (temp->name == name) {
                temp->status = newStatus;
                cout << "Status updated successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Task not found\n";
    }
};

int main() {
    // Testing Josephus
    cout << "Josephus Problem (N=7, M=3)" << endl;
    cout << "Survivor: " << josephus(7, 3) << endl << endl;

    // Testing Task Scheduler
    TaskScheduler ts;

    ts.addTask("Design UI", 2);
    ts.addTask("Write Code", 1);
    ts.addTask("Testing", 3);
    ts.addTask("Documentation", 2);

    cout << "All Tasks:" << endl;
    ts.displayAll();

    cout << "\nUpdating status..." << endl;
    ts.updateStatus("Write Code", "in-progress");

    cout << "\nAfter Update:" << endl;
    ts.displayAll();

    return 0;
}