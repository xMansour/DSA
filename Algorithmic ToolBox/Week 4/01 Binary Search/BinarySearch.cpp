#include <iostream>
#include <cmath>

using namespace std;

int recursiveBinarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    int mid = floor((high + low) / 2);
    cout << "mid: " << mid << " ";
    if (arr[mid] == key)
        return 1;
    else if (key < arr[mid])
        return recursiveBinarySearch(arr, low, mid - 1, key);
    else
        return recursiveBinarySearch(arr, mid + 1, high, key);
}

int iterativeBinarySearch(int arr[], int low, int high, int key)
{
    while (high > low)
    {
        int mid = floor((high + low) / 2);
        cout << "mid: " << mid << " ";
        if (arr[mid] == key)
            return 1;
        else if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 3, 5, 6, 7, 8, 10, 15, 30, 55};
    int numToSearch;
    cout << "Enter number to search for in the array arr: ";
    cin >> numToSearch;
    cout << "Searching for number: " << numToSearch << " In the array arr using recursiveBinarySearch: " << recursiveBinarySearch(arr, 0, 9, numToSearch) << "\n";

    cout << "Searching for number: " << numToSearch << " In the array arr using iterativeBinarySearch: " << iterativeBinarySearch(arr, 0, 9, numToSearch) << "\n";
}