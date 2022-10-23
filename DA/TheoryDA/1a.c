#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

void insertAtTail(int data);
void displaySinglyLinkedList();
void deleteAlternateNodes();

int main()
{
    insertAtTail(10);
    insertAtTail(20);
    insertAtTail(30);
    insertAtTail(40);
    insertAtTail(50);
    insertAtTail(60);
    insertAtTail(70);
    insertAtTail(80);
    insertAtTail(90);
    insertAtTail(100);

    displaySinglyLinkedList(head);
    deleteAlternateNodes();
    displaySinglyLinkedList(head);
    return 0;
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

void deleteAlternateNodes()
{
    node *currNode = head;
    while (currNode->next->next != NULL)
    {
        node *nodeToDelete = currNode->next;
        currNode->next = currNode->next->next;
        printf("Deleting data %d\n", nodeToDelete->data);
        free(nodeToDelete);

        currNode = currNode->next;
    }
}