#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "common.h"

#define MAX_LEN 100

node *root = NULL;
int idx = 0;

void insertNode(int data);
void DisplayPreOrderTraversal(node *root);
void DisplayInOrderTraversal(node *root);
void DisplayPostOrderTraversal(node *root);
void searchNode(int data);
void deleteNode(int data);
node *getInOrderSuccNode(node *currentNode);
int inorderTraversalArr(node *root, int *arr, int i);
void addToArr(node *currentNode, int level, int *arr);
void addToArray(int *arr);
int heightOfTree(node* currentNode);
int max(int a,int b);
void mirrorBinaryTreeRecursion(node*);
void mirrorBinaryTreeIteration();

int main()
{
    int binaryTreeArr[MAX_LEN] = {0};

    insertNode(11);
    insertNode(6);
    insertNode(8);
    insertNode(19);
    insertNode(4);
    insertNode(10);
    insertNode(5);
    insertNode(17);
    insertNode(43);
    insertNode(49);
    insertNode(31);


    // deleteNode(4)
    
    // int height = heightOfTree(root);

    // for (int j = 0; j < height; j++)
    // {
    //     addToArr(root,j,binaryTreeArr);
    // }

    // mirrorBinaryTreeRecursion(root);
    mirrorBinaryTreeIteration(root);
    addToArray(binaryTreeArr);

    printf("The Binary Tree converted to array is: ");
    for (int i = 0; i < 15; i++)
    {
        printf("%d ",binaryTreeArr[i]);
    }
    printf("\n");

    printf("Pre Order Traversal of binary tree: ");
    DisplayPreOrderTraversal(root);
    printf("\n");

    printf("In Order Traversal of binary tree: ");
    DisplayInOrderTraversal(root);
    printf("\n");

    printf("Post Order Traversal of binary tree: ");
    DisplayPostOrderTraversal(root);
    printf("\n");

    return 0;
}

void insertNode(int data)
{
    node *tempNode = (node *)malloc(sizeof(node));
    node *currentNode;
    node *parentNode;

    if (tempNode == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }

    tempNode->data = data;
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;

    if (root == NULL)
    {
        root = tempNode;

        return;
    }

    currentNode = root;
    parentNode = NULL;

    while (currentNode != NULL)
    {
        parentNode = currentNode;
        if (data < parentNode->data)
        {
            currentNode = currentNode->leftChild;
        }
        else
        {
            currentNode = currentNode->rightChild;
        }
    }

    if (data < parentNode->data)
    {
        parentNode->leftChild = tempNode;
    }
    else
    {
        parentNode->rightChild = tempNode;
    }

    return;
}

void searchNode(int data)
{
    node *currentNode = root;
    int level = 0;

    while (currentNode != NULL)
    {
        if (currentNode->data == data)
        {
            printf("The level of searched node is %d\n", level);
            return;
        }

        if (currentNode->data < data)
        {
            currentNode = currentNode->rightChild;
            level++;
        }
        else
        {
            currentNode = currentNode->leftChild;
            level++;
        }
    }

    printf("No Node with the given data\n");
    return;
}

void deleteNode(int data)
{
    node *currentNode = root;
    node *parentNode = NULL;
    while ((currentNode != NULL) && (currentNode->data != data))
    {
        parentNode = currentNode;
        if (currentNode->data < data)
        {
            currentNode = currentNode->rightChild;
        }
        else
        {
            currentNode = currentNode->leftChild;
        }
    }

    if (currentNode == NULL)
    {
        printf("The Node with given data doesnt exist\n");
        return;
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

    if ((currentNode->leftChild != NULL) && (currentNode->rightChild != NULL))
    {
        node *inOrderSuccNode = getInOrderSuccNode(root->rightChild);
        int newData = inOrderSuccNode->data;
        deleteNode(inOrderSuccNode->data);
        currentNode->data = newData;
        return;
    }
}

int inorderTraversalArr(node *currentNode, int arr[], int i)
{
    if(currentNode == NULL)
        return i;

    arr[i] = currentNode->data;
    i++;

    if(currentNode->leftChild != NULL)
        i = inorderTraversalArr(currentNode->leftChild, arr, i);
    if(currentNode->rightChild != NULL)
        i = inorderTraversalArr(currentNode->rightChild, arr, i);

    return i;    
}

void addToArr(node *currentNode, int level, int *arr)
{
    if (currentNode == NULL)
    {
        arr[idx] = 0;
        idx++;
        return;
    }
    
    if (level == 0)
    {
        arr[idx] = currentNode->data;
        idx++;
    }
    else
    {
        addToArr(currentNode->leftChild,level-1,arr);
        addToArr(currentNode->rightChild,level-1,arr);
    }
}

void addToArray(int *arr)
{   
    if (root == NULL)
    {
        printf("Root is NULL");
        return;
    }

    enqueue(root);

    while (isEmpty() == false)
    {
        node* dequeuedNode = dequeue();

        if (dequeuedNode != NULL)
        {
            if (dequeuedNode->leftChild != NULL)
            {
                enqueue(dequeuedNode->leftChild);
            }

            if (dequeuedNode->rightChild != NULL)
            {
                enqueue(dequeuedNode->rightChild);
            }

        
            arr[idx] = dequeuedNode->data;
        }
        else
        {
            arr[idx] = 0;
        }

        idx++;
    }
    
}

int heightOfTree(node* currentNode)
{
    if (currentNode == NULL)
    {
        return 0;
    }
    
    return 1+max(heightOfTree(currentNode->leftChild),heightOfTree(currentNode->rightChild));
}

int max(int a,int b)
{
    return (a>b) ? a : b;
}

node *getInOrderSuccNode(node *currentNode)
{
    while (currentNode->leftChild != NULL)
    {
        currentNode = currentNode->leftChild;
    }
    return currentNode;
}

void DisplayInOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    DisplayInOrderTraversal(root->leftChild);
    printf("%d ", root->data);
    DisplayInOrderTraversal(root->rightChild);
}

void DisplayPreOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    printf("%d ", root->data);
    DisplayPreOrderTraversal(root->leftChild);
    DisplayPreOrderTraversal(root->rightChild);
}

void DisplayPostOrderTraversal(node *root)
{
    if (root == NULL)
    {
        return;
    }

    DisplayPostOrderTraversal(root->leftChild);
    DisplayPostOrderTraversal(root->rightChild);
    printf("%d ", root->data);
}

void mirrorBinaryTreeRecursion(node* currentNode)
{
    if (currentNode== NULL)
    {
        return;
    }
    
    node *temp;

    mirrorBinaryTreeRecursion(currentNode->leftChild);
    mirrorBinaryTreeRecursion(currentNode->rightChild);

    temp = currentNode->leftChild;
    currentNode->leftChild = currentNode->rightChild;
    currentNode->rightChild = temp;
    
}

void mirrorBinaryTreeIteration()
{
    if (root == NULL)
    {
        printf("The Binary tree is Empty");
        return;
    }

    enqueue(root);
    
    while (false == isEmpty())
    {
        node *dequeuedNode = dequeue();
        node *temp;
        temp = dequeuedNode->leftChild;
        dequeuedNode->leftChild = dequeuedNode->rightChild;
        dequeuedNode->rightChild = temp;

        if (dequeuedNode->leftChild != NULL)
        {
            enqueue(dequeuedNode->leftChild);
        }

        if (dequeuedNode->rightChild != NULL)
        {
            enqueue(dequeuedNode->rightChild);
        }
    }

}