#include <iostream>
using namespace std;

int recursiveLinearSearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;
    if (arr[low] == key)
        return 1;
    return recursiveLinearSearch(arr, low + 1, high, key);
}

int iterativeLinearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 5, 6, 7, 9, 5, 2, 3, 4};
    int numToSearch;
    cout << "Enter number to search for in the array arr: ";
    cin >> numToSearch;
    cout << "Searching for number: " << numToSearch << " In the array arr using recursiveLinearSearch: " << recursiveLinearSearch(arr, 0, 8, numToSearch) << "\n";

    cout << "Searching for number: " << numToSearch << " In the array arr using iterativeLinearSearch: " << iterativeLinearSearch(arr, 8, numToSearch) << "\n";
}