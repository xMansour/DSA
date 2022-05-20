#include <iostream>
class Node
{
public:
    int data;
    Node *right, *left;
    Node(int value)
    {
        data = value;
        right = left = NULL;
    }
};