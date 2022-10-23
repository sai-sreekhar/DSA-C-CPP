#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    char data;
    struct NODE *leftChild;
    struct NODE *rightChild;
} node;

node *root = NULL;
int idx = 0;

void DisplayPreOrderTraversal(node *root);
void DisplayInOrderTraversal(node *root);
void DisplayPostOrderTraversal(node *root);
int heightOfTree(node *currentNode);
int max(int a, int b);
int getNoOfLeaves(node *root);

int main()
{

    root->data = 'a';
    root->leftChild->data = 'b';
    root->rightChild->data = 'c';
    root->rightChild->data = 'c';


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

    if (currNode->leftChild && currNode->rightChild)
    {
        printf("Degree of node %d is 0\n", currNode->data);
    }
    else if (currNode->leftChild || currNode->rightChild)
    {
        printf("Degree of node %d is 1\n", currNode->data);
    }

    if (currNode->leftChild == NULL && currNode->rightChild == NULL)
    {
        printf("Leaf Nodes are %d\n", currNode->data);
        printf("Degree of node %d is 2\n", currNode->data);
        count++;
        return count;
    }

    getNoOfLeaves(currNode->leftChild);
    getNoOfLeaves(currNode->rightChild);
}
