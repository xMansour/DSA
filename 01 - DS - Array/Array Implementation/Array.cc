#include <iostream>
using namespace std;
class CustomArray
{
private:
    int length;
    int customArraySize;
    int *arrPtr;

public:
    CustomArray(int size)
    {
        customArraySize = size;
        length = 0;
        arrPtr = new int[customArraySize]; // dynamic memory allocation
    }

    void fill()
    {
        int elementsNumber;
        cout << "How many elements do you want to insert\n";
        cin >> elementsNumber;
        if (elementsNumber > customArraySize)
        {
            cout << "Array size is smaller than the number of elements";
            return;
        }

        for (int i = 0; i < elementsNumber; i++)
        {
            cin >> arrPtr[i];
            length++;
        }
    }

    void display()
    {
        cout << "Array contents: ";

        for (int i = 0; i < length; i++)
        {
            cout << arrPtr[i] << "\t";
        }
        cout << "\n";
    }

    int getSize()
    {
        return customArraySize;
    }

    int getLength()
    {
        return length;
    }

    int search(int key)
    {
        int index = -1;
        for (int i = 0; i < length; i++)
        {
            if (arrPtr[i] == key)
            {
                index = i;
                break;
            }
        }
        return index;
    }

    void append(int element)

    {
        if (length >= customArraySize)
        {
            cout << "Error!, Overflow";
            return;
        }
        arrPtr[length] = element;
        length++;
    }

    void insertAt(int index, int element)
    {
        if (index >= customArraySize)
        {
            cout << "Index is greater than the array size\n";
            return;
        }
        if (index < 0)
        {
            cout << "Index out of range\n";
            return;
        }

        for (int i = length; i > index; i--)
        {
            arrPtr[i] = arrPtr[i - 1];
        }
        arrPtr[index] = element;
        length++;
    }

    void deleteElement(int index)
    {
        cout << "index: " << index;
        for (int i = index; i < length; i++)
        {
            arrPtr[i] = arrPtr[i + 1];
        }
        length--;
    }

    void enlarge(int size)
    {
        if (customArraySize >= size)
        {
            cout << "Size should be greater than current size\n";
            return;
        }
        int *oldArrPtr = arrPtr;
        arrPtr = new int[size];
        for (int i = 0; i < length; i++)
        {
            arrPtr[i] = oldArrPtr[i];
        }
        delete[] oldArrPtr;
        customArraySize = size;
    }

    void merge(CustomArray customArray)
    {
        int newSize = customArraySize + customArray.getSize();
        customArraySize = newSize;
        int *oldArrPtr = arrPtr;
        arrPtr = new int[customArraySize];
        int i;
        for (i = 0; i < length; i++)
        {
            arrPtr[i] = oldArrPtr[i];
        }
        delete[] oldArrPtr;
        for (int j = 0; j < customArray.getLength(); j++)
        {
            arrPtr[i++] = customArray.arrPtr[j];
            length++;
        }
    }
};