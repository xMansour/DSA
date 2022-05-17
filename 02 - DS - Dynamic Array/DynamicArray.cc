#include <iostream>
using namespace std;
class DynamicArray
{

private:
    int _size = 0;
    int minCap = 2;
    const int GROWTH_FACTOR = 2;
    int *arr;

public:
    DynamicArray()
    {
        _size = 0;
        arr = new int[minCap];
    }

    int get(int index)
    {
        return arr[index];
    }

    void push(int element)
    {
        cout << "_size: " << _size << "\n";
        cout << "minCap: " << minCap << "\n";
        if (_size == minCap)
        {
            cout << "_size==minCap= " << _size << " when adding element: " << element << "\n";
            resize();
        }
        arr[_size] = element;
        _size++;
        cout << "added: " << element << "\n";
    }

    void deleteAt(int index)
    {
        if (index > _size)
        {
            cout << "Out of range";
            return;
        }
        for (int i = index; i <= _size; i++)
        {
            arr[i] = arr[i + 1];
        }
        _size--;
    }

    int length()
    {
        return _size;
    }

    int cap()
    {
        return minCap;
    }

    void resize()
    {
        minCap *= GROWTH_FACTOR;
        int *temp = new int[minCap];
        copy(temp);
        delete[] arr;
        arr = temp;
    }

    void copy(int temp[])
    {
        for (int i = 0; i < _size; i++)
        {
            temp[i] = arr[i];
        }
    }
};