#include <iostream>
#include "Node.cc"
using namespace std;
void printList(Node *node);
void pushAtStart(Node **head, int data);
void pushAfter(Node *prevNode, int data);
void pushAtEnd(Node **head, int data);
void deleteNode(Node **node, int data);
int main()
{

    Node *head = new Node();
    Node *secondNode = new Node();
    Node *thirdNode = new Node();

    head->value = 1;
    head->nextNode = secondNode;

    secondNode->value = 2;
    secondNode->nextNode = thirdNode;

    thirdNode->value = 3;
    thirdNode->nextNode = NULL;

    printList(head);
    pushAtStart(&head, 4);
    printList(head);
    pushAfter(secondNode, 20);
    printList(head);
    pushAtEnd(&head, 80);
    printList(head);
    pushAtEnd(&head, 70);
    printList(head);
    deleteNode(&head, 4);
    printList(head);

    return 0;
}

void printList(Node *node)
{
    cout << "Print start:___________________________________\n";

    while (node != NULL)
    {
        cout << node->value << "\n";
        node = node->nextNode;
    }
    cout << "Print end:___________________________________\n";
}

// Time complexity of push() is O(1)
// Pointer to pointer (refrence)
void pushAtStart(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->nextNode = *head;
    *head = newNode;
}

// Time complexity of insertAfter() is O(1)
void pushAfter(Node *prevNode, int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->nextNode = prevNode->nextNode;
    prevNode->nextNode = newNode;
}
// Time complexity of pushAtEnd() is O(n) can be optimized to O(1) by keeping a pointer to the tail of the list
void pushAtEnd(Node **head, int data)
{
    Node *newNode = new Node();
    newNode->value = data;
    newNode->nextNode = NULL;
    Node *lastNode = *head;
    // if there is no nodes yet
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    while (lastNode->nextNode != NULL)
    {
        lastNode = lastNode->nextNode;
    }
    lastNode->nextNode = newNode;
}

void deleteNode(Node **node, int data)
{
    Node *temp;
    temp = *node;
    Node *prev = NULL;
    // if head is to be deleted
    if (temp != NULL && temp->value == data)
    {
        *node = temp->nextNode;
        delete temp;
        return;
    }
    else
    {
        while (temp != NULL && temp->value != data)
        {
            prev = temp;
            temp = temp->nextNode;
        }

        // If key was not present in linked list
        if (temp == NULL)
            return;

        // Unlink the node from linked list
        prev->nextNode = temp->nextNode;

        // Free memory
        delete temp;
    }
}