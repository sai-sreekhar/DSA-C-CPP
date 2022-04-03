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
        printf("Memory Allocation Failed");
        return;
    }
    
    link->data = data;
    link->next = head;
    head = link;

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

int main()
{
    insertAtHead(100);
    insertAtHead(1000);
    
    displaySinglyLinkedList();

    return 0;
}