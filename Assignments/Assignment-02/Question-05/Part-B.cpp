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

    int peek()
    {
        return top->data;
    }
};

// Insertion sort using stacks
// sorted stack keeps the smallest element on top
void insertSorted(Stack &s, int x)
{
    Stack temp;
    // remove the elements smaller than x
    while (!s.isEmpty() && s.peek() < x)
    {
        temp.push(s.pop());
    }
    s.push(x);
    // put the removed elements back
    while (!temp.isEmpty())
    {
        s.push(temp.pop());
    }
}

int main()
{
    int a[6] = {5, 2, 9, 1, 7, 3};
    int n = 6;
    Stack sorted;

    cout << "Before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        insertSorted(sorted, a[i]);
    }

    cout << "After sorting: ";
    while (!sorted.isEmpty())
    {
        cout << sorted.pop() << " ";
    }
    cout << endl;
    return 0;
}
