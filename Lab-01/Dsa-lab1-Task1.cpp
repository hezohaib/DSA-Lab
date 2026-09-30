#include <iostream>
using namespace std;

class ArrayList
{
private:
    int arr[100]; // array to store values
    int size;     // current size of list

public:
    // constructor
    ArrayList()
    {
        size = 0;
    }

    // insert at the end
    void insertAtEnd(int value)
    {
        arr[size] = value;
        size++;
    }

    // insert at the start
    void insertAtStart(int value)
    {
        // shift all elements to the right
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        size++;
    }

    // insert after a specific value
    void insertAfter(int specificValue, int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == specificValue)
            {
                // shift elements to make space
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

    // insert before a specific value
    void insertBefore(int specificValue, int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == specificValue)
            {
                // shift elements to make space
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

    // print the list
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // delete last element
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

    // delete first element
    void deleteFromStart()
    {
        if (size > 0)
        {
            // shift elements to the left
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

    // delete a specific value
    void deleteSpecific(int value)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == value)
            {
                // shift elements to fill the gap
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