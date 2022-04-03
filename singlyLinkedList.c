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
    free(head);
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

    free((curNode->next)->next);
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
    }
    else if (pos == getLengthOfSinglyLinkedList() + 1)
    {
        insertAtTail(data);
    }
    else
    {
        int curPos = 1;
        node* curNode = head;
        node* pvsNode;
        while (curPos != pos)
        {
            curPos++;
            pvsNode = curNode;
            curNode = curNode->next;
        }

        pvsNode->next = link;
        link->next = curNode;
        link->data = data;
    }

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

    printf("The length Of SinglyLinkedList is %d\n", length);
    return length;
}

void displaySinglyLinkedList()
{
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

int main()
{
    insertAtTail(5);
    insertAtHead(1);
    insertAtHead(2);
    insertAtHead(3);
    insertAtPos(10,4);

    displaySinglyLinkedList();

    return 0;
}