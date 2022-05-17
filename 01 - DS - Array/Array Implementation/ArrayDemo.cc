#include <iostream>
#include "Array.cc"
using namespace std;

void searchForNum(CustomArray customArray)
{
    int num;
    cout << "What number do you want to search for: ";
    cin >> num;
    int numIndex = customArray.search(num);
    if (numIndex == -1)
    {
        cout << "Item not found\n";
    }
    else
    {
        cout << "item: " << num << " is found at index: " << numIndex << "\n";
    }
}

void displayArrayData(CustomArray customArray)
{
    cout << "________________________________________________________\n";
    customArray.display();
    cout << "Size: " << customArray.getSize() << "\n";
    cout << "Length: " << customArray.getLength() << "\n";
    cout << "________________________________________________________\n";
}
int main()
{

    int arraySize;
    cout << "Enter array size: ";
    cin >> arraySize;
    CustomArray customArray(arraySize);
    customArray.fill();
    displayArrayData(customArray);
    // searchForNum(customArray);
    // customArray.append(20);
    // displayArrayData(customArray);
    // customArray.insertAt(3, 50);
    // displayArrayData(customArray);
    // customArray.deleteElement(3);
    // displayArrayData(customArray);
    // customArray.enlarge(7);
    // displayArrayData(customArray);
    cout << "Enter second array size: ";
    cin >> arraySize;
    CustomArray secondCustomArray(arraySize);
    secondCustomArray.fill();
    displayArrayData(secondCustomArray);
    customArray.merge(secondCustomArray);
    displayArrayData(customArray);
}
