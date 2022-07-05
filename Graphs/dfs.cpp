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
    char buffer[1024 + 2] = {0};

    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << flush;
}

typedef struct Node
{
    int vertex;
    struct Node *next;
}node;

node *createNode(int v);

typedef struct Graph
{
    int numVertices;
    int *visited;
    node **adjLists;
}graph;

void DFS(graph *graphDS, int vertex)
{
    node *adjList = graphDS->adjLists[vertex];
    node *temp = adjList;

    graphDS->visited[vertex] = 1;
    printf("Visited %d \n", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;

        if (graphDS->visited[connectedVertex] == 0)
        {
            DFS(graphDS, connectedVertex);
        }
        temp = temp->next;
    }
}

node *createNode(int v)
{
    node *newNode = new node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(int vertices)
{
    graph *graphDS = new graph;
    graphDS->numVertices = vertices;

    graphDS->adjLists = new node*[vertices];

    graphDS->visited = new int[vertices];

    int i;
    for (i = 0; i < vertices; i++)
    {
        graphDS->adjLists[i] = NULL;
        graphDS->visited[i] = 0;
    }
    return graphDS;
}

void addEdge(graph *graphDS, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graphDS->adjLists[src];
    graphDS->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graphDS->adjLists[dest];
    graphDS->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    struct Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    DFS(graph, 2);

    return 0;
}