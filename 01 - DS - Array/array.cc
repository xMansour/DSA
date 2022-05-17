#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    arr[0] = 1; // O(1)
    arr[1] = 2; // O(1)
    arr[2] = 3; // O(1)
    arr[3] = 4; // O(1)
    arr[4] = 5; // O(1)

    int length = sizeof(arr) / sizeof(int);
    for (int i = 0; i < length; i++) // O(n)
    {
        cout << arr[i] << "\t"; // O(1)
    }

}