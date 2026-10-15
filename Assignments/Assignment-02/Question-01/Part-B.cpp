#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void push(int x)
    {
        Node *temp = new Node;
        temp->data = x;
        temp->next = top;
        top = temp;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        Node *temp = top;
        int x = temp->data;
        top = top->next;
        delete temp;
        return x;
    }
};

// Queue using two stacks
class Queue
{
    Stack s1, s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }

    int dequeue()
    {
        // if s2 is empty, move all elements from s1 to s2
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        if (s2.isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return s2.pop();
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.enqueue(40);
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    q.dequeue();
    return 0;
}
