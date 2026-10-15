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

// Selection sort using two queues
void selectionSort(Queue &q, Queue &sorted, int n)
{
    for (int i = 0; i < n; i++)
    {
        int size = n - i;

        // find the smallest element
        int min = 99999;
        for (int j = 0; j < size; j++)
        {
            int x = q.dequeue();
            if (x < min)
            {
                min = x;
            }
            q.enqueue(x);
        }

        // move the smallest element to sorted queue
        bool found = false;
        for (int j = 0; j < size; j++)
        {
            int x = q.dequeue();
            if (x == min && found == false)
            {
                sorted.enqueue(x);
                found = true;
            }
            else
            {
                q.enqueue(x);
            }
        }
    }
}

int main()
{
    int a[6] = {64, 25, 12, 22, 11, 90};
    int n = 6;
    Queue q, sorted;

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
        q.enqueue(a[i]);
    }
    cout << endl;

    selectionSort(q, sorted, n);

    cout << "After sorting: ";
    while (!sorted.isEmpty())
    {
        cout << sorted.dequeue() << " ";
    }
    cout << endl;
    return 0;
}
