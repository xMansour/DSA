#include <iostream>
using namespace std;
int *rotate(int arr[], int arrayLength, int offset);
int main()
{

    int arrToRotate[] = {1, 2, 3, 4, 5};
    const int arrayLength = sizeof(arrToRotate) / sizeof(int);
    const int rotationOffset = 3;
    int *arrPtr = rotate(arrToRotate, arrayLength, rotationOffset);
    for (int i = 0; i < arrayLength; i++)
    {
        cout << *(arrPtr + i) << endl;
    }
}

int *rotate(int arr[], int arrayLength, int rotationOffset)
{
    int temp[arrayLength];
    // reverse first elemnts untill offset temp[] = {2, 1}
    for (int i = 0; i < rotationOffset; i++)
    {
        temp[i] = arr[rotationOffset - 1 - i];
    }
    // reverse elemnts after offset temp[] = {2, 1, 5, 4, 3}
    for (int i = 0; i < arrayLength - rotationOffset; i++)
    {
        temp[i + rotationOffset] = arr[arrayLength - 1 - i];
    }
    // rotate elemnts after offset temp[] = {3, 4, 5, 1, 2}
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = temp[arrayLength - 1 - i];
    }

    return arr;
}