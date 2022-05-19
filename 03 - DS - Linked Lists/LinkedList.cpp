#include <iostream>
using namespace std;
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    bool isEmpty()
    {
        return (head == NULL);
    }

    void insertFirst(int data)
    {
        Node *newNode = new Node();
        newNode->value = data;
        if (isEmpty())
        {

            newNode->nextNode = NULL;
            head = newNode;
        }
        else
        {

            newNode->nextNode = head;
            head = newNode;
        }
    }

    void display()
    {
        if (isEmpty())
            return;
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << "\t";
            temp = temp->nextNode;
        }
    }

    int count()
    {
        int counter = 0;
        if (isEmpty())
            return 0;
        Node *temp = head;

        while (temp != NULL)
        {
            counter++;
            temp = temp->nextNode;
        }

        return counter;
    }

    bool isFound(int key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->value == key)
                return true;
            temp = temp->nextNode;
        }
        return false;
    }

    void insertBefore(int item, int data)
    {
        if (isEmpty())
            insertFirst(item);
        else
        {
            if (isFound(item))
            {

                Node *newNode = new Node();
                newNode->value = data;
                Node *temp = head;
                while (temp != NULL && temp->nextNode->value != item)
                {
                    temp = temp->nextNode;
                }
                newNode->nextNode = temp->nextNode;
                temp->nextNode = newNode;
            }
        }
    }

    void append(int data)
    {
        if (isEmpty())
        {
            insertFirst(data);
        }
        else
        {
            Node *newNode = new Node();
            newNode->value = data;
            newNode->nextNode = NULL;
            Node *temp = head;
            while (temp->nextNode != NULL)
            {
                temp = temp->nextNode;
            }
            temp->nextNode = newNode;
        }
    }

    void deleteItem(int key)
    {
        if (!isEmpty())
        {
            if (isFound(key))
            {
                if (head->value == key)
                {
                    Node *temp = head;
                    head = head->nextNode;
                    delete temp;
                }
                else
                {
                    Node *prev = NULL;
                    Node *delNode = head;
                    while (delNode->value != key)
                    {
                        prev = delNode;
                        delNode = delNode->nextNode;
                    }
                    prev->nextNode = delNode->nextNode;
                    delete delNode;
                }
            }
        }
    }
};