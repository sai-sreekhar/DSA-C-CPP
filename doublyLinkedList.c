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
    struct Node *pvs;
} node;

node *head = NULL;
node *tail = NULL;

void insertAtHead(int data);
void deleteAtHead();
void insertAtTail(int data);
void deleteAtTail();
void insertAtPos(int data, int pos);
void deleteAtPos(int pos);
void freeAllNodes();
void freeNode(node *nodeToFree);
int getLengthOfDoublyLinkedList();
void displayDoublyLinkedList();
void displayReverseDoublyLinkedList();
void bubbleSortDoublyLinkedList();
void reverseDoublyLinkedList();

int main()
{
    insertAtHead(10000);
    insertAtTail(2000);
    // insertAtHead(30000);
    // insertAtHead(100);
    // insertAtPos(1,4);
    // deleteAtHead();
    // deleteAtHead();
    // deleteAtTail();
    // deleteAtTail();
    // deleteAtPos(3);
    displayDoublyLinkedList();
    displayReverseDoublyLinkedList();
    reverseDoublyLinkedList();
    // bubbleSortDoublyLinkedList();
    displayDoublyLinkedList();
    displayReverseDoublyLinkedList();

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

    if ((head == NULL) && (tail == NULL))
    {
        link->next = NULL;
        link->pvs = NULL;
        head = link;
        tail = link;

        return;
    }

    head->pvs = link;
    link->next = head;
    link->pvs = NULL;
    head = link;

    return;
}

void deleteAtHead()
{
    if ((head == NULL) && (tail == NULL))
    {
        printf("The DoublyLinkedList is Empty\n");
        return;
    }

    if (head == tail)
    {
        freeNode(head);
        head = NULL;
        tail = NULL;

        return;
    }

    node *newHead = head->next;
    newHead->pvs = NULL;
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

    if ((head == NULL) && (tail == NULL))
    {
        head = link;
        link->pvs = NULL;
        tail = link;
        return;
    }

    link->pvs = tail;
    tail->next = link;
    tail = link;

    return;
}

void deleteAtTail()
{
    if (head == NULL)
    {
        printf("The DoublyLinkedList is Empty\n");
        return;
    }

    if (head == tail)
    {
        freeNode(head);
        head = NULL;
        tail = NULL;
        return;
    }

    node *newTail = tail->pvs;
    newTail->next = NULL;
    freeNode(tail);
    tail = newTail;

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

    link->data = data;
    pvsNode->next = link;
    link->pvs = pvsNode;
    link->next = curNode;

    if (curNode == NULL)
    {
        tail = link;

        return;
    }

    curNode->pvs = link;

    return;
}

void deleteAtPos(int pos)
{
    if ((head == NULL) && (tail == NULL))
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

    if (curNode->next == NULL)
    {
        free(tail);
        tail = pvsNode;
        return;
    }

    (curNode->next)->pvs = pvsNode;
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
    tail = NULL;
    return;
}

void freeNode(node *nodeToFree)
{
    memset(nodeToFree, 0, sizeof(node));
    free(nodeToFree);

    return;
}

int getLengthOfDoublyLinkedList()
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

void displayDoublyLinkedList()
{
    if (head == NULL)
    {
        printf("Doubly linkedlist is empty\n");
        return;
    }

    node *curNode = head;
    int pos = 1;

    while (curNode != NULL)
    {
        printf("The element as position %d is %d\n", pos, curNode->data);
        curNode = curNode->next;
        pos++;
    }

    return;
}

void displayReverseDoublyLinkedList()
{
    if (head == NULL)
    {
        printf("Doubly linkedlist is empty\n");
        return;
    }

    node *curNode = tail;

    while (curNode != NULL)
    {
        printf("The element is %d\n", curNode->data);
        curNode = curNode->pvs;
    }

    return;
}

void bubbleSortDoublyLinkedList()
{
    int length = getLengthOfDoublyLinkedList();

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

void reverseDoublyLinkedList()
{
    node *pvsNode = NULL;
    node *curNode = head;
    node *nextNode = NULL;

    tail = head;
    while (curNode != NULL)
    {
        nextNode = curNode->next;
        curNode->next = pvsNode;
        curNode->pvs = nextNode;
        pvsNode = curNode;
        curNode = nextNode;
    }
    head = pvsNode;

    return;
}