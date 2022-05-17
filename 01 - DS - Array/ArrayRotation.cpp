#include <iostream>
using namespace std;
int *rotate(int arr[], int arrayLength, int offset);
int main()
{

    int arrToRotate[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    const int arrayLength = sizeof(arrToRotate) / sizeof(int);
    const int rotationOffset = 2;
    int *arrPtr = rotate(arrToRotate, arrayLength, rotationOffset);
    for (int i = 0; i < arrayLength; i++)
    {
        cout << *(arrPtr + i) << endl;
    }
}

int *rotate(int arr[], int arrayLength, int rotationOffset)
{
    int temp[arrayLength];
    for (int i = 0; i < arrayLength; i++)
    {
        // 1,2,3,4,5,6,7,8,9   => by 2    3,4,5,6,7,8,9,1,2
        // for i = 0 temp 0 => arr[9-1-2-0] = arr[6]
        // temp[i] = arr[arrayLength - 1 - rotationOffset - i]; reverse

        temp[i] = arr[(i + rotationOffset) % arrayLength];
    }
    for (int i = 0; i < arrayLength; i++)
    {
        arr[i] = temp[i];
    }

    return arr;
}