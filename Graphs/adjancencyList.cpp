#include <iostream>
#include<bits/stdc++.h>
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
}graph;

node *createNode(int v)
{
    node* newNode = new node;
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph *createAGraph(int vertices)
{
    graph *graphDS = new graph;
    graphDS->numVertices = vertices;

    graphDS->adjLists = new node*[vertices];

    for (int i = 0; i < vertices; i++)
    {
        graphDS->adjLists[i] = NULL;
    }

    return graphDS;
}


void addEdge(graph *graphDS, int s, int d)
{
    
    node *newNode = createNode(d);
    newNode->next = graphDS->adjLists[s];
    graphDS->adjLists[s] = newNode;

    newNode = createNode(s);
    newNode->next = graphDS->adjLists[d];
    graphDS->adjLists[d] = newNode;
}

void printGraph(graph *graphDS)
{
    for (int v = 0; v < graphDS->numVertices; v++)
    {
        node *temp = graphDS->adjLists[v];
        printf("\n Vertex %d\n: ", v);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    graph *graphDS = createAGraph(4);
    addEdge(graphDS, 0, 1);
    addEdge(graphDS, 0, 2);
    addEdge(graphDS, 0, 3);
    addEdge(graphDS, 1, 2);

    printGraph(graphDS);

    return 0;
}