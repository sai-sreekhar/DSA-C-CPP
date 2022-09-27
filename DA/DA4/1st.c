#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct NODE
{
    int data;
    struct NODE *leftChild;
    struct NODE *rightChild;
} node;

node *root = NULL;

void insertNode(int data);
void DisplayPreOrderTraversal(node *root);
void DisplayInOrderTraversal(node *root);
void DisplayPostOrderTraversal(node *root);

int main()
{
    insertNode(3);
    insertNode(1);
    insertNode(4);
    insertNode(6);
    insertNode(9);
    insertNode(2);
    insertNode(5);
    insertNode(7);

    printf("The InOrder Traversal of Tree is: ");
    DisplayInOrderTraversal(root);
    printf("\n");
    printf("The PreOrder Traversal of Tree is: ");
    DisplayPreOrderTraversal(root);
    printf("\n");
    printf("The PostOrder Traversal of Tree is: ");
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
