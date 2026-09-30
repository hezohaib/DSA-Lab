#include <iostream>
using namespace std;

class ArrayList
{
private:
    int arr[100]; // array to hold elements
    int size;     // current number of elements

public:
    // initialize empty list
    ArrayList()
    {
        size = 0;
    }

    // add element to the end of array
    void insertAtEnd(int value)
    {
        arr[size] = value;
        size++;
    }

    // print all elements in array
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // search for value step-by-step
    void linearSearch(int value)
    {
        int i = 0;

        while (i < size)
        {
            if (arr[i] == value)
            {
                cout << "Value found at index " << i << endl;
                return;
            }
            i++;
        }
        cout << "Value not found!" << endl;
    }
};

int main()
{
    ArrayList list;

    // populate the list with initial values
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);

    cout << "Array List: ";
    list.display();

    // get search input from user
    int value;
    cout << "Enter value to search: ";
    cin >> value;

    // run linear search
    list.linearSearch(value);

    return 0;
}