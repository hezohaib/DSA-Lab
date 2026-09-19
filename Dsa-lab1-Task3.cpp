
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
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
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

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.insertAtEnd(50);
    cout << "Array List: ";
    list.display();
    int value;
    cout << "Enter value to search: ";
    cin >> value;

    list.linearSearch(value);

    return 0;
}