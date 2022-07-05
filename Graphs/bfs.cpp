#include <iostream>
#include <iostream>
#include <cstdlib>
#include <new>
#include <cmath>
#include <cstring>
#include <cstdbool>
#include <cctype>
#include <cstdarg>
#include <climits>

#define DEBUG

#ifdef DEBUG
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#else
#define TRACE(msg, ...)
#endif

using namespace std;

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024+2] = { 0 };

    snprintf(buffer, sizeof(buffer), "%s(%d) : " , fileName, line);
    int stringLength = strnlen(buffer,1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer+stringLength,remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

#define SIZE 50

typedef struct Queue
{
    int items[SIZE];
    int front;
    int rear;
}queue;

queue *createQueue();
void enqueue(queue *q, int);
int dequeue(queue *q);
void display(queue *q);
int isEmpty(queue *q);
void printQueue(queue *q);

typedef struct Node
{
    int vertex;
    struct Node *next;
}node;

node *createNode(int);

typedef struct Graph
{
    int numVertices;
    node **adjLists;
    int *visited;
}graph;

void bfs(graph *graphDS, int startVertex)
{
    queue *q = createQueue();

    graphDS->visited[startVertex]= 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        node *temp = graphDS->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graphDS->visited[adjVertex] == 0)
            {
                graphDS->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

node *createNode(int v)
{
    node *newNode = new node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    graph *graphDS = new graph;
    graphDS->numVertices = vertices;

    graphDS->adjLists = new node*[vertices];
    graphDS->visited = new int[vertices];

    for (int i = 0; i < vertices; i++)
    {
        graphDS->adjLists[i] = NULL;
        graphDS->visited[i] = 0;
    }

    return graphDS;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

queue *createQueue()
{
    queue *q = new queue;
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int value)
{
    if (q->rear == SIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Resetting queue ");
            q->front = q->rear = -1;
        }
    }
    return item;
}

void printQueue(queue *q)
{
    int i = q->front;

    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i = q->front; i < q->rear + 1; i++)
        {
            printf("%d ", q->items[i]);
        }
    }
}

int main()
{
    struct Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    bfs(graph, 0);

    return 0;
}