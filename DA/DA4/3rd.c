#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *leftChild;
    struct NODE *rightChild;
} node;

node *root = NULL;
int idx = 0;

void insertNode(int data);
void DisplayPreOrderTraversal(node *root);
void DisplayInOrderTraversal(node *root);
void DisplayPostOrderTraversal(node *root);
int heightOfTree(node *currentNode);
int max(int a, int b);
node *getInOrderSuccNode(node *currentNode);
int getNoOfLeaves(node *root);

int main()
{

    insertNode(25);
    insertNode(20);
    insertNode(36);
    insertNode(10);
    insertNode(22);
    insertNode(30);
    insertNode(40);
    insertNode(5);
    insertNode(12);
    insertNode(28);
    insertNode(38);
    insertNode(48);

    printf("The Height of Tree is %d\n", heightOfTree(root) - 1);
    printf("The InOrder Traversal of Tree is: ");
    DisplayInOrderTraversal(root);
    printf("\n");
    printf("The PreOrder Traversal of Tree is: ");
    DisplayPreOrderTraversal(root);
    printf("\n");
    printf("The PostOrder Traversal of Tree is: ");
    DisplayPostOrderTraversal(root);
    printf("\n");
    printf("The No Of Leaves in Tree are %d\n", getNoOfLeaves(root));
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

int heightOfTree(node *currentNode)
{
    if (currentNode == NULL)
    {
        return 0;
    }

    return 1 + max(heightOfTree(currentNode->leftChild), heightOfTree(currentNode->rightChild));
}

int max(int a, int b)
{
    return (a > b) ? a : b;
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

int count = 0;
int getNoOfLeaves(node *currNode)
{
    if (currNode == NULL)
    {
        return count;
    }

    if (currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
        count++;
        return count;
    }
    getNoOfLeaves(currNode->leftChild);
    getNoOfLeaves(currNode->rightChild);
}
