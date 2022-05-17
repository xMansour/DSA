#include <iostream>
#include "DynamicArray.cc"
using namespace std;
void printArray(DynamicArray dynamicArray);
int main()
{

    DynamicArray dynamicArray;
    printArray(dynamicArray);
    dynamicArray.push(1);
    dynamicArray.push(2);
    dynamicArray.push(3);
    dynamicArray.push(4);
    dynamicArray.push(5);
    dynamicArray.push(6);
    dynamicArray.push(1);
    dynamicArray.push(2);
    dynamicArray.push(3);
    dynamicArray.push(4);
    dynamicArray.push(5);
    dynamicArray.push(6);
    printArray(dynamicArray);

    dynamicArray.deleteAt(0);
    dynamicArray.deleteAt(1);
    dynamicArray.deleteAt(2);

    printArray(dynamicArray);
    dynamicArray.push(1);
    dynamicArray.push(2);
    dynamicArray.push(3);
    dynamicArray.push(4);
    dynamicArray.push(5);
    dynamicArray.push(6);
    dynamicArray.push(1);
    dynamicArray.push(2);
    dynamicArray.push(3);
    dynamicArray.push(4);
    dynamicArray.push(5);
    dynamicArray.push(6);
    printArray(dynamicArray);
}

void printArray(DynamicArray dynamicArray)
{
    cout << "___________________________________________" << endl;

    for (int i = 0; i < dynamicArray.length(); i++)
    {
        cout << "Element at index: " << i << " = " << dynamicArray.get(i) << endl;
    }

    cout << "Length: " << dynamicArray.length() << endl;
    cout << "Cap: " << dynamicArray.cap() << endl;
    cout << "___________________________________________" << endl;
}