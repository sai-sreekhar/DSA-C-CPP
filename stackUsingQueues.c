#include <stdio.h>
#include <stdlib.h>

#define QUEUE_EMPTY_MAGIC 0xdeadbeef
typedef struct queue
{
    int *arr;
    int rear;
    int front;
    int presentCount;
    int max;
} queue;

queue *allocateMemory(int n);
void insertQueue(queue *q, int data);
int removeQueue(queue *q);
int queueCount(queue *q);
int queueEmpty(queue *q);

void stack_push(queue *q, int data)
{
    insertQueue(q, data);
}

int stack_pop(queue *q)
{
    int i, n = queueCount(q);
    int removed_element;

    for (i = 0; i < (n - 1); i++)
    {
        removed_element = removeQueue(q);
        insertQueue(q, removed_element);
    }
    removed_element = removeQueue(q);

    return removed_element;
}

int stack_is_empty(queue *q)
{
    return queueEmpty(q);
}

int stack_count(queue *q)
{
    return queueCount(q);
}

int queueCount(queue *q)
{
    return q->presentCount;
}

queue *
allocateMemory(int n)
{
    queue *queue;

    queue = malloc(sizeof(queue));
    queue->max = n;

    queue->arr = malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;

    return queue;
}

void insertQueue(queue *q, int data)
{
    if (q->presentCount == q->max)
        return;

    q->rear = (q->rear + 1) % q->max;
    q->arr[q->rear] = data;
    q->presentCount++;
}

int removeQueue(queue *q)
{
    int retval;

    if (q->presentCount == 0)
        return QUEUE_EMPTY_MAGIC;

    q->front = (q->front + 1) % q->max;
    retval = q->arr[q->front];
    q->presentCount--;

    return retval;
}

int queueEmpty(queue *q)
{
    return (q->presentCount == 0);
}

void queue_display(queue *q)
{
    int i = (q->front + 1) % q->max, elements = queueCount(q);

    while (elements--)
    {
        printf("[%d], ", q->arr[i]);
        i = (i >= q->max) ? 0 : (i + 1);
    }
}

#define MAX 128
int main(void)
{
    queue *q;
    int x, select;
    q = allocateMemory(MAX);

    do
    {
        printf("\n[1] Push\n[2] Pop\n[0] Exit");
        printf("\nChoice: ");
        scanf(" %d", &select);

        switch (select)
        {
        case 1:
            printf("\nEnter value to Push:");
            scanf(" %d", &x);
            stack_push(q, x);

            printf("\n\n__________________________\nCurrent Queue:\n");

            queue_display(q);
            printf("\n\nPushed Value: %d", x);

            printf("\n__________________________\n");
            break;

        case 2:
            x = stack_pop(q);

            printf("\n\n\n\n__________________________\nCurrent Queue:\n");

            queue_display(q);
            if (x == QUEUE_EMPTY_MAGIC)
                printf("\n\nNo values removed");
            else
                printf("\n\nPopped Value: %d", x);

            printf("\n__________________________\n");
            break;

        case 0:
            printf("\nQutting.\n");
            return 0;

        default:
            printf("\nQutting.\n");
            return 0;
        }
    } while (1);

    return 0;
}
