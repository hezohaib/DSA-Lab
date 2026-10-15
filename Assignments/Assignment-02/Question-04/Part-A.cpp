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
