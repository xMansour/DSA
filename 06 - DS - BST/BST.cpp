#include <iostream>
using namespace std;
class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    Node *insert(Node *rootPtr, int item)
    {
        if (rootPtr == NULL)
        {
            Node *newNode = new Node(item);
            rootPtr = newNode;
        }
        else if (item < rootPtr->data)
            rootPtr->left = insert(rootPtr->left, item);
        else
            rootPtr->right = insert(rootPtr->right, item);

        return rootPtr;
    }

    void insert(int item)
    {
        root = insert(root, item);
    }

    void preOrderDisplay(Node *rootPtr)
    {
        if (rootPtr != NULL)
        {
            cout << rootPtr->data << "\t";
            preOrderDisplay(rootPtr->left);
            preOrderDisplay(rootPtr->right);
        }
    }

    void inOrderDisplay(Node *rootPtr)
    {
        if (rootPtr != NULL)
        {
            preOrderDisplay(rootPtr->left);
            cout << rootPtr->data << "\t";
            preOrderDisplay(rootPtr->right);
        }
    }

    void postOrderDisplay(Node *rootPtr)
    {
        if (rootPtr != NULL)
        {
            preOrderDisplay(rootPtr->left);
            preOrderDisplay(rootPtr->right);
            cout << rootPtr->data << "\t";
        }
    }

    Node *search(Node *rootPtr, int key)
    {
        if (rootPtr == NULL)
            return NULL;
        else if (key == rootPtr->data)
            return rootPtr;
        else if (key < rootPtr->data)
            return search(rootPtr->left, key);
        else
            return search(rootPtr->right, key);
    }

    bool search(int key)
    {
        Node *result = search(root, key);
        return (result != NULL);
    }

    Node *findMin(Node *rootPtr)
    {
        if (rootPtr == NULL)
            return NULL;
        else if (rootPtr->left == NULL)
            return rootPtr;
        else
            return findMin(rootPtr->left);
    }

    Node *findMax(Node *rootPtr)
    {
        if (rootPtr == NULL)
            return NULL;
        else if (rootPtr->right == NULL)
            return rootPtr;
        else
            return findMax(rootPtr->right);
    }

    Node *deleteNode(Node *rootPtr, int key)
    {
        if (rootPtr == NULL)
            return NULL;
        else if (key < rootPtr->data)
            rootPtr->left = deleteNode(rootPtr->left, key);
        else if (key > rootPtr->data)
            rootPtr->right = deleteNode(rootPtr->right, key);
        else
        {
            if (rootPtr->left == NULL && rootPtr->right == NULL)
            {
                delete rootPtr;
                rootPtr = NULL;
            }
            else if (rootPtr->left != NULL && rootPtr->right == NULL)
            {
                rootPtr->data = rootPtr->left->data;
                delete rootPtr->left;
                rootPtr->left = NULL;
            }
            else if (rootPtr->right != NULL && rootPtr->left == NULL)
            {
                rootPtr->data = rootPtr->right->data;
                delete rootPtr->right;
                rootPtr->right = NULL;
            }
            else
            {
                Node *pre = findMax(rootPtr->left);
                rootPtr->data = pre->data;
                rootPtr->left = deleteNode(rootPtr->left, pre->data);
            }
        }
        return rootPtr;
    }

    void deleteNode(int key)
    {
        Node *deletedNode = deleteNode(root, key);
    }
};