#include <iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int x)
    {
        if (top == 99)
        {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int x = arr[top];
        top--;
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
