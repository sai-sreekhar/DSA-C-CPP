#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue(int x)
{
    struct node *t;
    t = new struct node;
    if (t == NULL)
    {
        cout << "Queue is Filled\n";
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct node *t;
    if (front == NULL)
    {
        cout << "Empty Queue\n";
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        delete (t);
    }
    return x;
}

int isEmpty()
{
    return front == NULL;
}

void breadthFirstSearchTraversal(int graph[][10], int initial, int n)
{
    int i = initial, j;
    int visitedVertices[10] = {0};
    cout << i << " ";
    visitedVertices[i] = 1;
    enqueue(i);
    while (!isEmpty())
    {
        i = dequeue();
        for (j = 1; j < n; j++)
        {
            if (graph[i][j] == 1 && visitedVertices[j] == 0)
            {
                cout << j << " ";
                visitedVertices[j] = 1;
                enqueue(j);
            }
        }
    }
}

void depthFirstSearchTraversal(int graph[][10], int startVertex, int n)
{
    static int visitedVertices[10] = {0};
    if (visitedVertices[startVertex] == 0)
    {
        cout << startVertex << " ";
        visitedVertices[startVertex] = 1;
        for (int j = 1; j < n; j++)
        {
            if (graph[startVertex][j] == 1 && visitedVertices[j] == 0)
            {
                depthFirstSearchTraversal(graph, j, n);
            }
        }
    }
}

int main()
{
    int graph[10][10] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 1, 0, 1, 0, 0, 0, 0, 0},
                         {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                         {0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                         {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
                         {0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    cout << "BFS is:";
    breadthFirstSearchTraversal(graph, 1, 10);
    cout << "\n";
    cout << "DFS is:";
    depthFirstSearchTraversal(graph, 1, 10);
    cout << "\n";
    return 0;
}
