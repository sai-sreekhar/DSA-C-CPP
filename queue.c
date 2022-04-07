#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include "common.h"

queue *head = NULL;
queue *tail = NULL;

bool isEmpty()
{
    if ((head == NULL) && (tail == NULL))
    {
        return true;
    }
    return false;
}

void enqueue(node *binaryNode)
{

    queue *newNode = (queue *)malloc(sizeof(queue));
    if (newNode == NULL)
    {
        printf("Memory Allocation Failed");
        return;
    }
    
    newNode->next = NULL;
    newNode->data = binaryNode;

    if ((head == NULL) && (tail == NULL))
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;

    return;
}

node* dequeue()
{
    if ((head == NULL) && (tail == NULL))
    {
        return NULL;
    }
    
    node* val = head->data;

    if (head == tail)
    {
        free(head);
        head = NULL;
        tail = NULL;

        return val;
    }

    queue *newHead = head->next;

    free(head);
    head = newHead;

    return val;
}