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
int getLengthOfCircularDoublyLinkedList();
void displayCircularDoublyLinkedList();
void displayReverseCircularDoublyLinkedList();

int main()
{
    insertAtHead(10000);
    // insertAtTail(99);
    insertAtHead(30000);
    insertAtHead(5000);
    insertAtHead(2000);
    // insertAtTail(100);
    // insertAtPos(1,7);
    // deleteAtHead();
    // deleteAtHead();
    // deleteAtTail();
    // deleteAtTail();
    deleteAtPos(5);
    // reverseDoublyLinkedList();
    // bubbleSortDoublyLinkedList();
    displayCircularDoublyLinkedList();
    displayReverseCircularDoublyLinkedList();

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
        link->next = link;
        link->pvs = link;
        head = link;
        tail = link;

        return;
    }

    head->pvs = link;
    link->next = head;
    link->pvs = tail;
    tail->next = link;
    head = link;

    return;
}

void deleteAtHead()
{
    if ((head == NULL) && (tail == NULL))
    {
        printf("The CircularDoublyLinkedList is Empty\n");
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
    newHead->pvs = tail;
    tail->next = newHead;
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

    if ((head == NULL) && (tail == NULL))
    {
        head = link;
        link->pvs = link;
        link->next = link;
        tail = link;
        return;
    }

    link->pvs = tail;
    tail->next = link;
    link->next = head;
    head->pvs = link;
    tail = link;

    return;
}

void deleteAtTail()
{
    if ((head == NULL) && (tail == NULL))
    {
        printf("The Circular DoublyLinkedList is Empty\n");
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
    newTail->next = head;
    head->pvs = newTail;
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

    int curPos = 2;
    node *curNode = head->next;
    node *pvsNode = head;
    while ((curPos != pos) && (curNode != head))
    {
        curPos++;
        pvsNode = curNode;
        curNode = curNode->next;
    }

    link->data = data;
    pvsNode->next = link;
    link->pvs = pvsNode;
    link->next = curNode;

    if (curNode == head)
    {
        tail = link;
        head->pvs = link;

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

    int curPos = 2;
    node *curNode = head->next;
    node *pvsNode = head;

    while ((curPos != pos) && (curNode != head))
    {
        curPos++;
        pvsNode = curNode;
        curNode = curNode->next;
    }

    if (curNode == head)
    {
        printf("Invalid delete position\n");
        return;
    }

    pvsNode->next = curNode->next;
    (curNode->next)->pvs = pvsNode;
    tail = pvsNode;
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

int getLengthOfCircularDoublyLinkedList()
{
    int length = 0;
    node *curNode = head;

    while (curNode->next != head)
    {
        curNode = curNode->next;
        length++;
    }

    return length + 1;
}

void displayCircularDoublyLinkedList()
{
    if ((head == NULL) && (tail == NULL))
    {
        printf("Circular Doubly linkedlist is empty\n");
        return;
    }

    node *curNode = head;
    int pos = 1;

    while (curNode->next != head)
    {
        printf("The element as position %d is %d\n", pos, curNode->data);
        curNode = curNode->next;
        pos++;
    }
    printf("The element as position %d is %d\n", pos, curNode->data);
    return;
}

void displayReverseCircularDoublyLinkedList()
{
    if ((head == NULL) && (tail == NULL))
    {
        printf("Circular Doubly linkedlist is empty\n");
        return;
    }

    node *curNode = tail;

    while (curNode->pvs != tail)
    {
        printf("The element is %d\n", curNode->data);
        curNode = curNode->pvs;
    }

    printf("The element is %d\n", curNode->data);
    return;
}