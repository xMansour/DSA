#include <iostream>
using namespace std;

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    bool isEmpty()
    {
        return (top == NULL);
    }
    void push(int item)
    {
        Node *newNode = new Node();
        newNode->data = item;
        if (isEmpty())
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    int pop()
    {
        int value = -1;
        if (!isEmpty())
        {
            Node *delNode = top;
            top = top->next;
            value = delNode->data;
            delete delNode;
        }
        return value;
    }

    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }

    int count()
    {
        Node *temp = top;
        int counter = 0;
        while (temp != NULL)
        {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    bool isFound(int key)
    {
        Node *temp = top;
        while (temp != NULL)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    int peek()
    {
        return top->data;
    }
    bool isFull()
    {
        Node *newNode = new Node();
        if (newNode == NULL)
        {
            return true;
        }
        return false;
    }
};