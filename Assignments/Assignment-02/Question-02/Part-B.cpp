#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty()
    {
        return front == NULL;
    }

    void enqueue(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (rear == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        Node *temp = front;
        int x = temp->data;
        front = front->next;
        if (front == NULL)
        {
            rear = NULL;
        }
        delete temp;
        return x;
    }
};

// Stack using two queues
class Stack
{
    Queue q1, q2;

public:
    void push(int x)
    {
        q2.enqueue(x);
        // move old elements behind the new element
        while (!q1.isEmpty())
        {
            q2.enqueue(q1.dequeue());
        }
        // move everything back to q1
        while (!q2.isEmpty())
        {
            q1.enqueue(q2.dequeue());
        }
    }

    int pop()
    {
        if (q1.isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return q1.dequeue();
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.push(40);
    cout << "Popped: " << s.pop() << endl;
    cout << "Popped: " << s.pop() << endl;
    s.pop();
    return 0;
}
