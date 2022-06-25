#include <iostream>
#include <string>
#include <cstring>
#include <new>
#include <cstdbool>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstdarg>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024+2] = { 0 };
    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    
    int stringLength = strnlen(buffer,1024);
    int remainingBufferSize = 1024 - stringLength;

    va_start(args, msg);
    vsnprintf(buffer+stringLength,remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

typedef struct NODE
{
    int data;
    struct NODE *leftChild;
    struct NODE *rightChild;
    struct NODE *parent;
} node;

node *root = NULL;

void insertNode(int data)
{
    node *tempNode;
    node *currNode;
    node *parentNode;

    TRACE("Allocating Memory with data %d\n",data);
    try
    {
        tempNode = new node;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << "Allocation Failure" << endl;
        return;
    }

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    tempNode->parent = NULL;
    
    TRACE("When root is Null with data %d\n",data);
    if (NULL == root)
    {
        root = tempNode;
        return;
    }   
    
    currNode = root;
    parentNode = NULL;

    while (currNode != NULL)
    {
        parentNode = currNode;
        TRACE("Enetered Loop with data %d and currentNode data %d\n",data,currNode->data);
        if (data < currNode->data)
        {
            currNode = currNode->leftChild;
        }
        else
        {
            currNode = currNode->rightChild;
        }
        
    }

    TRACE("Checking data %d with parents node data %d\n",data,parentNode->data);
    if (data < (parentNode)->data)
    {
        (parentNode)->leftChild = tempNode;
        tempNode->parent = parentNode;
    }
    else
    {
        (parentNode)->rightChild = tempNode;
        tempNode->parent = parentNode;
    }
    
    return;
}

void inOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    inOrderTraversal(root->leftChild);
    cout << root->data << " ";
    inOrderTraversal(root->rightChild);

}

void deleteNode(int data)
{
    node *currNode= NULL;
    node *parentNode;
    while ((currNode != NULL) && (currNode->data != data))
    {
        parentNode = currNode;
        TRACE("Inside While Loop with currNode data %d",currNode->data);
        if (currNode-> data < data)
        {
            currNode = currNode->rightChild;
        }
        else
        {
            currNode = currNode->leftChild;
        }  
    }

    TRACE("Check whether currNode is NULL given data is %d",data);

    if (currNode == NULL)
    {
        cout << "Doesn't exist"\n;
    }
    
    if ((currentNode->leftChild == NULL) && (currentNode->rightChild == NULL))
    {
        if (currentNode != root)
        {
            if (parentNode->leftChild == currentNode)
            {
                parentNode->leftChild = NULL;
            }
            else
            {
                parentNode->rightChild = NULL;
            }
        }
        else
        {
            root = NULL;
        }

        free(currentNode);
        return;
    }
    
    if ((currentNode->leftChild == NULL) || (currentNode->rightChild == NULL))
    {
        node *childNode = currentNode->leftChild ? currentNode->leftChild : currentNode->rightChild;
        if (currentNode != root)
        {
            if (currentNode == parentNode->leftChild)
            {
                parentNode->leftChild = childNode;
            }
            else
            {
                parentNode->rightChild = childNode;
            }
        }
        else
        {
            root = childNode;
        }

        free(currentNode);
        return;
    }


    
    
}

int main()
{
    TRACE("In Main, %d",1);

    insertNode(5);
    insertNode(9);
    insertNode(10);
    insertNode(7);
    insertNode(99);
    insertNode(2);
    // inOrderTraversal(root);
    return 0;
}