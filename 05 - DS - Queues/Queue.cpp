#include <iostream>
using namespace std;

class Queue
{
private:
    Node *rear;
    Node *front;

public:
    Queue()
    {
        front = rear = NULL;
    }

    bool isEmpty()
    {
        return (front == NULL);
    }

    void enqueue(int element)
    {
        Node *newNode = new Node();
        newNode->data = element;
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue()
    {
        if (!isEmpty())
        {
            if (front == rear)
            {
                delete front;
                front = rear = NULL;
            }
            else
            {
                Node *delNode = front;
                front = front->next;
                delete delNode;
            }
        }
    }

    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << "\n";
    }

    int getFront()
    {
        return front->data;
    }
    int getRear()
    {
        return rear->data;
    }

    int count()
    {
        Node *temp = front;
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
        Node *temp = front;
        while (temp != NULL)
        {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void clear()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};