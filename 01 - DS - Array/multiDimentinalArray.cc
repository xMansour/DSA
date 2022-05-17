#include <iostream>
using namespace std;

int main()
{
    int multiArr[2][2];
    multiArr[0][0] = 1; // O(1)
    multiArr[0][1] = 2; // O(1)
    multiArr[1][0] = 3; // O(1)
    multiArr[1][1] = 4; // O(1)

    int rowLength = sizeof(multiArr[0]) / sizeof(int);

    // total array access time n^2 O(n^2)
    for (int i = 0; i < rowLength; i++) // O(n)
    {
        for (int j = 0; j < rowLength; j++) // O(n)
        {
            cout << multiArr[i][j] << "\t"; // O(1)
        }
        cout << "\n";
    }
}