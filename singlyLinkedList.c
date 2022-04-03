#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

void insertAtHead(int data);
void deleteAtHead();
void insertAtTail(int data);
void deleteAtTail();
void insertAtPos(int data, int pos);
void deleteAtPos(int pos);
void freeAllNodes();
void freeNode(node *nodeToFree);
int getLengthOfSinglyLinkedList();
void displaySinglyLinkedList();
void bubbleSortSinglyLinkedList();

int main()
{
    // insertAtTail(5000);
    // insertAtHead(10000);
    // insertAtHead(2000);
    // insertAtHead(30000);
    // insertAtPos(10, 5);

    // deleteAtPos(7);
    bubbleSortSinglyLinkedList();
    displaySinglyLinkedList();

    return 0;
}

void insertAtHead(int data)
{
    node *link = (node *)malloc(sizeof(node));

    if (link == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    link->data = data;
    link->next = head;
    head = link;

    return;
}

void deleteAtHead()
{
    if (head == NULL)
    {
        printf("The SinglyLinkedList is Empty\n");
        return;
    }

    node *newHead = head->next;
    freeNode(head);
    head = newHead;

    return;
}

void insertAtTail(int data)
{
    node *link = (node *)malloc(sizeof(node));

    if (link == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    link->data = data;
    link->next = NULL;

    if (head == NULL)
    {
        head = link;
        link->next = NULL;
        return;
    }

    node *curNode = head;
    while (curNode->next != NULL)
    {
        curNode = curNode->next;
    }
    curNode->next = link;

    return;
}

void deleteAtTail()
{
    if (head == NULL)
    {
        printf("The SinglyLinkedList is Empty\n");
        return;
    }

    node *curNode = head;

    if (curNode->next == NULL)
    {
        free(curNode);
        head = NULL;
        return;
    }

    while ((curNode->next)->next != NULL)
    {
        curNode = curNode->next;
    }

    freeNode((curNode->next)->next);
    curNode->next = NULL;

    return;
}

void insertAtPos(int data, int pos)
{
    node *link = (node *)malloc(sizeof(node));

    if (link == NULL)
    {
        printf("Memory Allocation Failed\n");
        return;
    }

    if (pos == 1)
    {
        insertAtHead(data);
        return;
    }

    int curPos = 1;
    node *curNode = head;
    node *pvsNode = NULL;
    while ((curPos != pos) && (curNode != NULL))
    {
        curPos++;
        pvsNode = curNode;
        curNode = curNode->next;
    }

    pvsNode->next = link;
    link->next = curNode;
    link->data = data;

    return;
}

void deleteAtPos(int pos)
{
    if (head == NULL)
    {
        printf("The SinglyLinkedList is empty\n");
        return;
    }

    if (pos == 1)
    {
        deleteAtHead();
        return;
    }

    int curPos = 1;
    node *curNode = head;
    node *pvsNode = NULL;

    while ((curPos != pos) && (curNode != NULL))
    {
        curPos++;
        pvsNode = curNode;
        curNode = curNode->next;
    }

    if (curNode == NULL)
    {
        printf("Invalid delete position\n");
        return;
    }

    pvsNode->next = curNode->next;
    freeNode(curNode);

    return;
}

void freeAllNodes()
{
    node *curNode = head;
    while (curNode != NULL)
    {
        node *tempNode = curNode;
        curNode = curNode->next;

        freeNode(tempNode);
    }

    head = NULL;
    return;
}

void freeNode(node *nodeToFree)
{
    memset(nodeToFree, 0, sizeof(node));
    free(nodeToFree);

    return;
}

int getLengthOfSinglyLinkedList()
{
    int length = 0;
    node *curNode = head;

    while (curNode != NULL)
    {
        curNode = curNode->next;
        length++;
    }

    return length;
}

void displaySinglyLinkedList()
{
    node *curNode = head;
    int pos = 1;

    while (curNode != NULL)
    {
        printf("The element as position %d is %d %p\n", pos, curNode->data, curNode->next);
        curNode = curNode->next;
        pos++;
    }

    return;
}

void bubbleSortSinglyLinkedList()
{
    int length = getLengthOfSinglyLinkedList();

    if (length == 0)
    {
        printf("The SinglyLinkedList is Empty\n");
        return;
    }
    
    if (length == 1)
    {
        return;
    }

    node *currentNode = NULL;
    node *nextNode = NULL;

    for (int i = 0; i < length - 1; i++)
    {
        currentNode = head;
        nextNode = head->next;

        for (int j = 0; j < length - i - 1; j++)
        {
            if (currentNode->data > nextNode->data)
            {
                int tempData = currentNode->data;
                currentNode->data = nextNode->data;
                nextNode->data = tempData;
            }

            currentNode = currentNode->next;
            nextNode = nextNode->next;
        }
    }

    return;
}