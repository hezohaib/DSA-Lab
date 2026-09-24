#include <iostream>
using namespace std;

class ArrayList
{
private:
    int arr[100];
    int size;

public:

    ArrayList()
    {
        size = 0;
    }
    void insertAtEnd(int value)
    {
        arr[size] = value;
        size++;
    }

    void insertAtStart(int value)
    {
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;
    }

    void insertAfter(int specificValue, int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == specificValue)
            {
                for (int j = size; j > i + 1; j--)
                {
                    arr[j] = arr[j - 1];
                }

                arr[i + 1] = value;
                size++;
                return;
            }
        }

        cout << "Specific value not found!" << endl;
    }

    void insertBefore(int specificValue, int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == specificValue)
            {
                for (int j = size; j > i; j--)
                {
                    arr[j] = arr[j - 1];
                }

                arr[i] = value;
                size++;
                return;
            }
        }

        cout << "Specific value not found!" << endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
   
    void deleteFromEnd()
    {
        if (size > 0)
        {
            size--;
        }
        else
        {
            cout << "List is empty!" << endl;
        }
    }

    void deleteFromStart()
    {
        if (size > 0)
        {
            for (int i = 0; i < size - 1; i++)
            {
                arr[i] = arr[i + 1];
            }

            size--;
        }
        else
        {
            cout << "List is empty!" << endl;
        }
    }

    void deleteSpecific(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }

                size--;
                return;
            }
        }

        cout << "Value not found!" << endl;
    }
};

int main()
{
    ArrayList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    list.insertAtStart(5);

    list.insertAfter(20, 25);

    list.insertBefore(30, 27);

    cout << "Array List: ";
    list.display();

    list.deleteFromEnd();

    cout << "After deleting from end: ";
    list.display();

    list.deleteFromStart();

    cout << "After deleting from start: ";
    list.display();

    list.deleteSpecific(20);

    cout << "After deleting 20: ";
    list.display();

    return 0;
}