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
