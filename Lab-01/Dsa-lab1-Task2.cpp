#include <iostream>
using namespace std;

int main()
{
    // variables to store user input
    int start, stop;
    int sum = 0; // keeps track of total sum

    cout << "Enter starting value: ";
    cin >> start;

    cout << "Enter stopping value: ";
    cin >> stop;

    // loop from start to stop and add squares
    for (int x = start; x <= stop; x++)
    {
        sum = sum + (x * x); // add square of current number
    }

    // print the total sum
    cout << "Sum of X^2 = " << sum << endl;

    return 0;
}