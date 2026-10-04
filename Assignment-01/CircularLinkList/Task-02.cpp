#include <iostream>
#include <string>
using namespace std;

// Task 2: Round-robin task scheduler using circular linked list
struct Task { string name; int priority; string status; Task* next; };
Task *head = NULL, *current = NULL;          // current = where next search starts

// Add a task at the end, list stays circular
void addTask(string name, int p, string st) {
    Task* n = new Task{name, p, st, NULL};
    if (!head) { head = current = n; n->next = n; return; }
    Task* t = head;
    while (t->next != head) t = t->next;
    t->next = n;
    n->next = head;
}

// Remove a task by name
void removeTask(string name) {
    if (!head) return;
    Task *prev = head, *t = head;
    while (prev->next != head) prev = prev->next;        // prev = last node
    while (t->name != name) {
        prev = t;
        t = t->next;
        if (t == head) { cout << "Task not found" << endl; return; }
    }
    if (t->next == t) { head = current = NULL; delete t; return; }   // only one task
    if (current == t) current = t->next;
    if (head == t) head = t->next;
    prev->next = t->next;
    delete t;
}

// Get next pending task in round-robin order (skips non-pending tasks)
Task* nextTask() {
    if (!head) return NULL;
    Task* start = current;
    do {
        Task* t = current;
        current = current->next;
        if (t->status == "Pending") return t;
    } while (current != start);
    return NULL;
}

// Display all tasks from head until we return to head
void showTasks() {
    if (!head) { cout << "No tasks" << endl; return; }
    Task* t = head;
    do {
        cout << t->name << " | " << t->priority << " | " << t->status << endl;
        t = t->next;
    } while (t != head);
}

// Update status of a task by name and display it
void updateStatus(string name, string st) {
    if (!head) return;
    Task* t = head;
    do {
        if (t->name == name) {
            t->status = st;
            cout << t->name << " is now " << t->status << endl;
            return;
        }
        t = t->next;
    } while (t != head);
    cout << "Task not found" << endl;
}

int main() {
    addTask("Task1", 1, "Pending");
    addTask("Task2", 2, "Completed");
    addTask("Task3", 3, "Pending");
    cout << "All tasks:" << endl;
    showTasks();

    Task* t = nextTask();
    cout << "Next task: " << t->name << endl;
    t = nextTask();
    cout << "Next task: " << t->name << endl;   // Task2 is completed so it is skipped

    updateStatus("Task1", "In-Progress");
    removeTask("Task2");
    cout << "After changes:" << endl;
    showTasks();
    return 0;
}