#include <iostream>
#include "Node.cc"
#include "LinkedList.cpp"

using namespace std;

int main()
{
    int n;
    LinkedList linkedList;
    cout << "How many elements to add? ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int data;
        cout << "Enter element no." << i << ": ";
        cin >> data;
        linkedList.append(data);
        cout << "\n";
    }

    linkedList.insertBefore(7, 20);
    linkedList.deleteItem(6);
    cout << "Linked List contains " << linkedList.count() << " elements and they are: "
         << "\n";
    linkedList.display();
}