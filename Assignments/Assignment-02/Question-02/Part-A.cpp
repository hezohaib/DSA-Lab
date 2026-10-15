#include <iostream>
using namespace std;

class Queue
{
    int arr[100];
    int front, rear, count;

public:
    Queue()
    {
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    void enqueue(int x)
    {
        if (count == 100)
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = (rear + 1) % 100;
        arr[rear] = x;
        count++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        front = (front + 1) % 100;
        count--;
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
