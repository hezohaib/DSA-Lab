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

// Bubble sort using a queue
void bubbleSort(Queue &q, int n)
{
    for (int pass = 1; pass < n; pass++)
    {
        int first = q.dequeue();
        for (int i = 1; i < n; i++)
        {
            int second = q.dequeue();
            if (first > second)
            {
                q.enqueue(second);
            }
            else
            {
                q.enqueue(first);
                first = second;
            }
        }
        q.enqueue(first);
    }
}

int main()
{
    int a[6] = {64, 25, 12, 22, 11, 90};
    int n = 6;
    Queue q;

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
        q.enqueue(a[i]);
    }
    cout << endl;

    bubbleSort(q, n);

    cout << "After sorting: ";
    while (!q.isEmpty())
    {
        cout << q.dequeue() << " ";
    }
    cout << endl;
    return 0;
}
