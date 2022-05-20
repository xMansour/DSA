#include <iostream>
#include "Node.cpp"
#include "BST.cpp"
using namespace std;
int main()
{
    BST bst;
    bst.insert(1);
    bst.insert(2);
    bst.insert(0);
    bst.insert(4);
    bst.insert(5);
    bst.insert(-1);
    bst.insert(7);
    bst.insert(8);
    bst.insert(9);

    bst.preOrderDisplay(bst.root);
    cout << "\n.....................................................................\n";
    bst.inOrderDisplay(bst.root);
    cout << "\n.....................................................................\n";
    bst.postOrderDisplay(bst.root);
    cout << "\n.....................................................................\n";

    cout << "Search: " << bst.search(10);
    cout << "\n.....................................................................\n";

    cout << "Min: " << (bst.findMin(bst.root))->data << "\n";
    cout << "Max: " << (bst.findMax(bst.root))->data << "\n";
    bst.deleteNode(1);
    bst.preOrderDisplay(bst.root);
    cout << "\n.....................................................................\n";
}