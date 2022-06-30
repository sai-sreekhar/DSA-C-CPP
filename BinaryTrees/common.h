#ifndef COMMON_H
#define COMMON_H

typedef struct NODE
{
    int data;
    struct NODE *leftChild;
    struct NODE *rightChild;
} node;

typedef struct Queue
{
    node* data;
    struct Queue *next;

} queue;

bool isEmpty();
void enqueue(node* binaryNode);
node* dequeue();

#endif